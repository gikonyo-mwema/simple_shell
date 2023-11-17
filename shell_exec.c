#include "shell.h"
/**
* execute_child - executes the child process
* @argv: command argument child process
* @command: command/path to be executed
* Return: void
*/
void execute_child(char **argv, char *command)
{
if (execve(command, argv, NULL) == -1)
{
perror("execve() failed");
free(command);
exit(EXIT_FAILURE);
}
}
/**
* execmd - executes a child process after validating permissions
* @argv: character array representing command arguments
* Return: 0
*/
int execmd(char **argv)
{
pid_t pid;

if (!argv || !argv[0])
_print_shell("Invalid command or arguments\n");
return (-1);
pid = fork();
if (pid == -1)
perror("fork() failed");
return (-1);
if (pid == 0)
{
char *command = (strchr(argv[0], '/') != NULL) ?
argv[0] : get_location(argv[0]);
if (!command)
{
_print_shell("Command not found\n");
return (-1);
}
if (access(command, X_OK) == 0)
{
execute_child(argv, command);
}
else
{
_print_shell("Permission denied or command not found\n");
}
free(command);
exit(EXIT_FAILURE);
}
else
{
int status;
waitpid(pid, &status, 0);
if (WIFEXITED(status))
{
return (WEXITSTATUS(status));
}
}
return (0);
}

