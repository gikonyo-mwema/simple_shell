#include "shell.h"
/**
* setup_pipe - configures the pipee to redirect output
* @pipefd: array of pipe file descriptors
* @argv: commands arguments to be executed
* Return: void
*/
void setup_pipe(int pipefd[2], char **argv)
{
close(pipefd[0]);
dup2(pipefd[1], STDOUT_FILENO);
close(pipefd[1]);
if (execvp(argv[0], argv) < 0)
{
perror(argv[0]);
exit(EXIT_FAILURE);
}
}
/**
* create_pipe - initializes and sets up a pipe
* @pipefd: array to store the file descriptors
* Return: 0 on success
*/
int create_pipe(int pipefd[2])
{
if (pipe(pipefd) < 0)
{
perror("pipe() failed");
return (-1);
}
return (0);
}
/**
* handle_child_processes - creation and execution of child processes
* @pipefd: array of file descriptors
* @argv_1: argments for first command
* @argv_2: arguments for second command
* Return: void
*/

void handle_child_processes(int pipefd[2], char **argv_1, char **argv_2)
{
pid_t pid1, pid2;

pid1 = fork();
if (pid1 < 0)
{
perror("fork() failed");
return;
}
if (pid1 == 0)
{
setup_pipe(pipefd, argv_1);
}
else
{
pid2 = fork();
if (pid2 < 0)
{
perror("fork() failed");
return;
}
if (pid2 == 0)
{
close(pipefd[1]);
dup2(pipefd[0], STDIN_FILENO);
close(pipefd[0]);
if (execvp(argv_2[0], argv_2) < 0)
{
perror(argv_2[0]);
exit(EXIT_FAILURE);
}
}
else
{
close(pipefd[0]);
close(pipefd[1]);
wait(NULL);
wait(NULL);
}
}
}
/**
* execute_pipe -  sets up a pipe between two commands and manages execution
* @argv_1: first command
* @argv_2: second command
* Return: void
*/
void execute_pipe(char **argv_1, char **argv_2)
{
int pipefd[2];

if (create_pipe(pipefd) == -1)
{
return;
}

handle_child_processes(pipefd, argv_1, argv_2);
}
