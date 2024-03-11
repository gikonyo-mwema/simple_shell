#include "shell.h"
/**
 * contains_redirection_or_pipe - checks if redirection or piping is present
 * @user_argv: pointer to command array
 * @program_name: name of program
 * Return: 1 redirection or piping found, 0 otherwise
 */
int contains_redirection_or_pipe(char **user_argv, const char *program_name)
{
	while (*user_argv != NULL)
	{
		if (strstr(*user_argv, ">") != NULL || strstr(*user_argv, "<") != NULL ||
				strstr(*user_argv, "|") != NULL)
		{
			fprintf(stderr, "%s: Error: Invalid input\n", program_name);
			return (1);
		}
		user_argv++;
	}
	return (0);
}
/**
 * contains_pipe - checks if command has pipe
 * @user_argv: pointer to an array of string command
 * @program_name: name of program
 * Return: 1 if pipe found, 0 if no pipe
 */
int contains_pipe(char **user_argv, const char *program_name)
{
	while (*user_argv != NULL)
	{
		if (strcmp(*user_argv, "|") == 0)
		{
			fprintf(stderr, "%s: Error: Invalid input\n", program_name);
			return (1);
		}
		user_argv++;
	}
	return (0);
}
/**
 * extract_first_command - extracts first command
 * @user_argv: pointer to command
 * @program_name: name of program
 * Return: pointer to first command
 */
char **extract_first_command(char **user_argv, const char *program_name)
{
	char **first_command = user_argv;

	while (*user_argv != NULL && strcmp(*user_argv, "|") != 0)
	{
		user_argv++;
	}
	if (*user_argv == NULL)
	{
		fprintf(stderr, "%s: Error: Invalid input\n", program_name);
		return (NULL);
	}
	*user_argv = NULL;
	return (first_command);
}
/**
 * extract_second_command - extracts second command and arguments
 * @user_argv: pointer to array of command
 * @program_name: name of program
 * Return: poiner to second command and its arguments
 */
char **extract_second_command(char **user_argv, const char *program_name)
{
	while (*user_argv != NULL && strcmp(*user_argv, "|") != 0)
	{
		user_argv++;
	}
	if (*user_argv == NULL || *(user_argv + 1) == NULL)
	{
		fprintf(stderr, "%s: Error: Invalid input\n", program_name);
		return (NULL);
	}
	return (user_argv + 1);
}
/**
 * extract_redirection_file - extract the file name
 * @user_argv: pointer to array of command and argments
 * @program_name: name of program
 * Return: pointer to the file name for redirection
 */
char *extract_redirection_file(char **user_argv, const char *program_name)
{
	while (*user_argv != NULL)
	{
		if (strcmp(*user_argv, ">") == 0 || strcmp(*user_argv, "<") == 0)
		{
			if (*(user_argv + 1) != NULL)
			{
				return (*user_argv + 1);
			}
			else
			{
				fprintf(stderr, "%s: Error: Invalid input\n", program_name);
				return (NULL);
			}
		}
		user_argv++;
	}
	return (NULL);
}
