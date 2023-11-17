#include "shell.h"
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	char *prompt = "($) ";
	const char *delim = " \n";
	char *lineptr = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			print_prompt(prompt);
		}

		lineptr = get_command();
		if (lineptr == NULL)
		{
			break;
		}

		execute_command(lineptr, delim);
	}

	return (0);
}
/**
 * execute_external_command - executes external command if path is found
 * @user_argv: array of user arguments
 * Return: void
 */
void execute_external_command(char **user_argv)
{
	char *executable_path;

	executable_path = get_location(user_argv[0]);
	if (executable_path != NULL)
	{
		execmd(user_argv);
		free(executable_path);
	}
	else
	{
		_print_shell("command not found");
	}
}
/**
 * execute_command - Executes the given command
 * @lineptr: pointer to the command line
 * @delim: delimiter for parsing command
 * Return: void
 */
void execute_command(char *lineptr, const char *delim)
{
	int i = 0;
	char *token = NULL;
	char **user_argv = parse_command(lineptr, delim);

	token = strtok(lineptr, delim);
	while (token != NULL)
	{
		user_argv[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	user_argv[i] = NULL;

	if (user_argv[0] != NULL)
	{
		if (is_builtin_command(user_argv[0]))
		{
			handle_builtin_commands(user_argv, lineptr);
		}
		else
		{
			execute_external_command(user_argv);
		}
	}

	free_resources(user_argv, lineptr);
}
/**
 * is_builtin_command - checks if a given command is built-in command
 * @command: command to check
 * Return: 1 for built-in, 0 otherwise
 */
int is_builtin_command(const char *command)
{
	if (strcmp(command, "exit") == 0 || strcmp(command, "env") == 0 ||
			strcmp(command, "setenv") == 0 || strcmp(command, "unsetenv") == 0)
	{
		return (1);
	}
	return (0);
}
/**
 * free_resources - Frees allocated resources for command execution
 * @user_argv: Array of user argument
 * @lineptr: Pointer to the command line
 * Return: void
 */
void free_resources(char **user_argv, char *lineptr)
{
	int i;

	free(lineptr);
	for (i = 0; user_argv[i] != NULL; i++)
	{
		free(user_argv[i]);
	}
	free(user_argv);
}
