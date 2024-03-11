#include "shell.h"
/**
 * unsetenv_inbuilt - Remove an environent variable
 * @args: Array of argument strings
 *
 * Return: void
 */
void unsetenv_builtin(char *args[])
{
	char *msg = "unsetenv: Syntax Error\n";

	if (args[1] == NULL)
	{
		write(STDOUT_FILENO, msg, strlen(msg));
		return;
	}

	if (unsetenv(args[1]) == -1)
	{
		perror("unsetenv");
	}
}
