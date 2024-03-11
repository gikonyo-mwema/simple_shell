#include "shell.h"

/**
 * setenv_inbuilt - Initialize a new environment variable
 * @args: Array of argument strings
 *
 * Return: void
 */
void setenv_inbuilt(char *args[])
{
	const char *msg;

	if (args[1] == NULL || args[2] == NULL)
	{
		msg = "setenv: Syntax Error\n";
		write(STDERR_FILENO, msg, strlen(msg));
		return;
	}

	if (setenv(args[1], args[2], 1) == -1)
	{
		perror("setenv");
	}
}
