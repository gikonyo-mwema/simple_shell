#include "shell.h"

#define BUFFER_SIZE 1024

/**
* custom_getline - reads input from file descriptor and extraccts line
* @fd: file descriptor (input source)
* @line: pointer to a pointer for read line
* Return: size of retrieved line
*/
ssize_t custom_getline(int fd, char **line)
{
size_t line_size = 0;
char *line_buffer = NULL;
char buffer[BUFFER_SIZE];
ssize_t bytes_read;
int i;

if (fd < 0 || line == NULL)
return (-1);
while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
{
for (i = 0; i < bytes_read; ++i)
{
if (buffer[i] == '\n')
{
line_buffer = realloc(line_buffer, line_size + 1);
if (line_buffer == NULL)
perror("Memory allocation error");
return (-1);
line_buffer[line_size] = '\0';
*line = line_buffer;
return (line_size);
}
else
{
char *temp = realloc(line_buffer, line_size + 2);
if (temp == NULL)
perror("Memory allocation error");
free(line_buffer);
return (-1);
line_buffer = temp;
line_buffer[line_size++] = buffer[i];
}
}
}
if (bytes_read == 0 && line_size == 0)
{
free(line_buffer);
return (-1);
}
return (line_size);
}
