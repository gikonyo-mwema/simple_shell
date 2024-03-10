#include "shell.h"

/**
 * execute_command - Execute the command
 * @command: Pointer to the command string
 * @args: Array of argument strings
 * @pstring: Pointer to the input string
 */
void execute_command(char *command, char *args[], char *pstring)
{
	char *path;
	char exec_path[1024];
	struct stat stats;
	char *command;
	char *path_dir;
	pid_t pid;

    /* Check for built-in commands */
	if (strcmp(command, "env") == 0)
	{
		env_inbuilt(args);
		free(pstring);
		continue;
	}
	else if (strcmp(command, "exit") == 0)
	{
		exit_builtin(args);
		free(pstring);
		continue;
	}

	/* Parsing the PATH */
	path = getenv("PATH");
	if (path == NULL)
	{
		perror("Error getting PATH");
		free(pstring);
		continue;
	}

    /* Find the executable */
    path_dir = find_executable(path, exec_path, command, &stats);

    /* Execute the command */
    if (path_dir == NULL)
    {
        printf("Command not found\n");
        free(pstring);
        return;
    }

    run_command(exec_path, args, pstring);
}