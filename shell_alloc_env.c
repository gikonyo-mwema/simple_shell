#include "main.h"
/**
 * allocate_env_output - allocates memory for environment variables output.
 * @env_p: pointer to environment variables
 * @lineptr: pointer to command line
 * @user_argv: Array of user arguments
 * Return: pointer to the environment output
 */
char *allocate_env_output(char **env_p, char *lineptr, char **user_argv)
{
	char *env = *env_p;
	char *env_output = NULL;
	size_t current_length = 0;
	size_t total_length = 0;

	while (env != NULL)
	{
		size_t env_length = strlen(env);
		size_t new_length = current_length + env_length + 2;
		char *temp = realloc(env_output, new_length);

		if (temp == NULL)
		{
			perror("Memory allocation error");
			free(env_output);
			free(lineptr);
			free(user_argv);
			exit(EXIT_FAILURE);
		}

		env_output = temp;
		strcat(env_output, env);
		strcat(env_output, "\n");

		current_length = new_length - 1;
		total_length += env_length + 1;
		env = *(++env_p);
	}

	return (env_output);
}
