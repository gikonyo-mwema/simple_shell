#include "shell.h"
/**
* setup_redirection - configures input or output redirection
* @argv: command arguments
* @file: file for redirection
* @direction: flag for direction
* Return: void
*/
void setup_redirection(char **argv, char *file, int direction)
{
int fd;

if (direction == 0)
{
fd = open(file, O_RDONLY);
if (fd < 0)
{
perror("Input redirection failed");
exit(EXIT_FAILURE);
}
dup2(fd, STDIN_FILENO);
}
else
{
fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
if (fd < 0)
{
perror("Output redirection failed");
exit(EXIT_FAILURE);
}
dup2(fd, STDOUT_FILENO);
}
close(fd);

if (execvp(argv[0], argv) < 0)
{
perror("execvp() failed");
exit(EXIT_FAILURE);
}
}
/**
* execute_redirection - manages input/output redirections
* @argv: user command arguments
* @file: file used for redirection
* @direction: flag for direction
* Return: void
*/
void execute_redirection(char **argv, char *file, int direction)
{
pid_t pid = fork();

if (pid == -1)
{
perror("fork() failed");
return;
}

if (pid == 0)
{
setup_redirection(argv, file, direction);
}
else
{
wait(NULL);
}
}

