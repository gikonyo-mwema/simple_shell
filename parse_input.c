#include "shell.h"

/**
 * parse_input - Parse the input string
 * @pstring: Pointer to the input string
 * @args: Array of argument string
 * Return: Pointer to the command string
 */
char **parse_input(char *pstring, char *args[])
{
	char *token;
	int i = 0;
	char **commands;

	commands = malloc(MAX_COMMANDS * sizeof(char *));

	/* Get the first token */
	token = strtok(pstring, " ");

	/* Walk through other tokens */
	while (token != NULL)
	{
		commands[i] = token;
		i++;
		token = strtok(NULL, " ;&&||");
	}
	commands = NULL;

	return (commands);
}
