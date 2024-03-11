#include "shell.h"

/**
 * find_executable - Find the executable in the PATH
 * @path: The PATH
 * @exec_path: The executable path
 * @command: The command
 * @stats: Pointer to a struct stat that will hold the file status information
 *
 * Return: The path directory if found, NULL otherwise
 */
char *find_executable(char *path, char *exec_path, char *command,
		struct stat *stats)
{
	char *path_dir = strtok(path, ":");

	while (path_dir != NULL)
	{
		sprintf(exec_path, "%s/%s", path_dir, command);
		if (stat(exec_path, stats) == 0)
		{
			/*printf("Executable found at %s\n", exec_path);*/
			break;
		}
		path_dir = strtok(NULL, ":");
	}
	return (path_dir);
}
