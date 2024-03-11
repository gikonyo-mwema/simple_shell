#include "shell.h"

/**
 * execute_command - Execute the command
 * @command: Pointer to the command string
 * @args: Array of argument strings
 * @pstring: Pointer to the input string
 *
 * Return: Exit status of the command
 */
int execute_command(char *command, char *args[], char *pstring)
{
	char *path, *path_dir;
	char exec_path[1024];
	struct stat stats;
	int exit_status = 0;
	char *msg = "No such file or directory\n";

	/* Check if command is an absolute path */
	if (command[0] == '/')
	{
		if (stat(command, &stats) == 0)
		{
			exit_status = run_command(command, args, pstring);
		}
		else
		{
			write(STDOUT_FILENO, msg, strlen(msg));
			exit_status = 1;
		}
		free(pstring);
		return (exit_status);
	}

	/* Check for built-in commands */
	if (check_builtin_commands(command, args, pstring))
	{
		free(pstring);
		return (exit_status);
	}

	/* If the command is not a built-in command,*/
	/* find the executable and run it */
	path = getenv("PATH");
	path_dir = find_executable(path, exec_path, command, &stats);
	if (path_dir == NULL)
	{
		write(STDOUT_FILENO, msg, strlen(msg));
		free(pstring);
		return (1);
	}
	else
	{
		exit_status = run_command(exec_path, args, pstring);
	}
	return (exit_status);
}
