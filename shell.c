#include "shell.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0 (Success)
 */
int main(int argc __attribute__((unused)),
		char *argv[] __attribute__((unused)))
{
	/* Create infinite loop for the prompt */
	while (1)
	{
		char *pstring = NULL;
		char *args[64];
		int i;
		char **command_and_args;
		char *command;

		/* Prompt and Read input from the user */
		pstring = read_input();

		/* Parse User Input */
		command_and_args = parse_input(pstring);

		/* Separate the command and its arguments */
		command = command_and_args[0];
		for (i = 0; command_and_args[i] != NULL; i++)
		{
			args[i] = command_and_args[i + 1];
		}
		args[i] = NULL; 

		/* Execute the command */
		execute_command(command, args, pstring);
	}
	return (0);
}
