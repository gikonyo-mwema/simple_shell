#include "shell.h"

/*
 * env_inbuilt - Implements the env built-in
 * Description: This function prints the current environment variables.
 * @args: Array of argument strings
 * Return: void
 */
void env_inbuilt(char **args __attribute__((unused)))
{
	char **current;

	for (current = environ; *current; current++)
	{
		printf("%s\n", *current);
	}
}

/**
 * exit_inbuilt - Implements the exit built-in
 * @args: Array of argument strings
 *
 * Return: void
 */
void exit_inbuilt(char **args __attribute__((unused)))
{
	exit(EXIT_SUCCESS);
}
