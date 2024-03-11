#include "shell.h"

/**
 * setenv_inbuilt - Initialize a new environment variable
 * @args: Array of argument strings
 *
 * Return: void
 */
void setenv_inbuilt(char *args[])
{
	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "setenv: Syntax Error\n");
		return;
	}

	if (setenv(args[1], args[2], 1) == -1)
	{
		perror("setenv");
	}
}
