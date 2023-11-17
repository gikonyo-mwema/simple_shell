#include "shell.h"
/**
 * handle_builtin_commands - handles built-in commands
 * @user_argv: array of user arguments
 * @lineptr: pointer to the command line
 * Return: void
 */
void handle_builtin_commands(char **user_argv, char *lineptr)
{
	char *env_output;

	if (strcmp(user_argv[0], "exit") == 0)
	{
		free_resources(user_argv, NULL);
		exit(0);
	}
	else if (strcmp(user_argv[0], "env") == 0)
	{
		env_output = allocate_env_output(environ, lineptr, user_argv);
		_print_shell(env_output);
		free(env_output);
	}
	else if (strcmp(user_argv[0], "setenv") == 0)
	{
		if (user_argv[1] != NULL && user_argv[2] != NULL)
		{
			my_setenv(user_argv[1], user_argv[2], "1");
		}
		else
		{
			_print_shell(" setenv: Too few arguments.");
		}
	}
	else if (strcmp(user_argv[0], "unsetenv") == 0)
	{
		if (user_argv[1] != NULL)
		{
			my_unsetenv(user_argv[1]);
		}
		else
		{
			_print_shell(" unsetenv: Too few arguments.");
		}
	}
}
