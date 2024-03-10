#include "shell.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	/* Create infinite loop for the prompt */
	while (1)
	{
		char *psting = NULL;
		char *args[64];
		char *command;

		/* Prompt and Read input from the user */
		pstring = read_input();

		/* Parse User Input */
		command = parse_input(pstring, args);

		/* Execute the command */
		execute_command(command, args, pstring);
	}
	return (0);
}
