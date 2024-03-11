#include "shell.h"
/**
 * unsetenv_inbuilt - Remove an environent variable
 * @args: Array of argument strings
 *
 * Return: void
 */
void unsetenv_builtin(char *args[])
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "unsetenv: Syntax Error\n);
		return;
	}

	if (unsetenv(args[1]) == -1)
	{
		perror("unsetenv");
	}
}
