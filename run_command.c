#include "shell.h"

/**
 * run_command - Run the command
 * @exec_path: The executable path
 * @args: Array of argument strings
 * @pstring: Pointer to the input string
 */
int run_command(char *exec_path, char *args[], char *pstring)
{
	pid_t pid = fork();
	int status = 0;

	if (pid < 0)
	{
		perror("Error forking");
		free(pstring);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(exec_path, args, environ) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		else
			status = 1;
	}
	free(pstring);
	return (status);
}
