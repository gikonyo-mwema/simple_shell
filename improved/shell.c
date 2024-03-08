#include "shell.h"

int main(int argc, char *argv[])
{
/*create infinite loop for the prompt*/
while(1)
{
    printf("$");
}

/*Read input form the user*/
ssize_t getline(char **pstring, size_t *size, FILE *stream);

/*Parse User Input*/
char *strtok(char *string, const char *delimiter);

/*Execute Commands*/
static char *newargv[] = {NULL};
static char *newenviron[] = {NULL};

if (argc != 2)
{
    fprintf(stderro, "Usage: %s <file-to-exec>\n", argv[0]);
    exit(EXIT_FAILURE);
}

newargv[0] = argv[1];

execve(argv[1], newargv, newenviron);
perror("execve");
exit(EXIT_FAILURE);
/*Handle EOF*/

/*Handle Path*/
/*Implement Built-in Commands*/
/*Support input/output Redirections*/
/*Support Pipes*/
/*Support Background Jobs*/

}
