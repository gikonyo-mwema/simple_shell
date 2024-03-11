#include "shell.h"

/**
 * cd_builtin - Changes the current directory 
 * @args: Array of argument strings
 *
 * Return: void
 */
void cd_builtin(char *args[])
{
	char *path;

	if (args[1] == NULL)
	{
		path = getenv("HOME");
	}
	else if (strcmp(args[1], "-") == 0)
	{
		path = getenv("OLDPWD");
	}
	else
	{
		path = args[1];
	}

	if (chdir(path) == -1)
	{
		perror("cd");
		return;
	}

	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", getcwd(NULL, 0), 1);
}
