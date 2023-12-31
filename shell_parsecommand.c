#include "shell.h"

#define BUFFER_SIZE 1024
/**
 * parse_command - Parses a command line into an array of arguments
 * @lineptr: Pointer to the command line to be parsed
 * @delim: Delimiter for tokenizing the command line
 * Return: array of string
 */
char **parse_command(char *lineptr, const char *delim)
{
	int token_num = 0, buf = BUFFER_SIZE;
	char **user_argv = malloc(sizeof(char *) * buf);
	char *token, **temp;
	int i;

	if (user_argv == NULL || lineptr == NULL)
	{
		return (NULL);
	}
	token = strtok(lineptr, delim);
	while (token != NULL)
	{
		if (token_num >= buf - 1)
		{
			temp = realloc(user_argv, sizeof(char *) * (buf * 2));
			if (temp == NULL)
			{
				perror("Memory allocation error");
				free(user_argv);
				return (NULL);
			}
			user_argv = temp;
			buf *= 2;
		}
		user_argv[token_num] = strdup(token);
		if (user_argv[token_num] == NULL)
		{
			perror("Memory allocation error");
			for (i = 0; i < token_num; i++)
			{
				free(user_argv[i]);
			}
			free(user_argv);
			return (NULL);
		}
		token_num++;
		token = strtok(NULL, delim);
	}
	user_argv[token_num] = NULL;
	return (user_argv);
}
