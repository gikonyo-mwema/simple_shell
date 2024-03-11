#include "shell.h"
/**
 * my_setenv - sets or modifies an environment variable
 * @name: name of environment variable
 * @value: value to set for variable
 * @overwrite: string showing whether to overwrite
 * Return: 0 success, -1 otherwise
 */
int my_setenv(const char *name, const char *value, char *overwrite)
{
	char *env_var;

	if (name == NULL || strchr(name, '=') != NULL)
	{
		return (-1);
	}

	/*Check if the variable already exists*/
	env_var = getenv(name);

	/*Variable already exists, overwrite flag not set */
	if (env_var != NULL && !atoi(overwrite))
	{
		return (0);
	}

	/*Create or modify the environment variable*/
	if (setenv(name, value, atoi(overwrite)) != 0)
	{
		return (-1);
	}

	return (0);
}
/**
 * my_unsetenv - Unsets/removes an environment variable
 * @name: environment variable
 * Return: 0 sucess, -1 otherwise
 */
int my_unsetenv(const char *name)
{
	char *env_var;

	if (name == NULL || strchr(name, '=') != NULL)
	{
		return (-1);
	}

	/*Check if the variable exists*/
	env_var = getenv(name);

	if (env_var == NULL)
	{
		return (0);
	}

	/*Remove the environment variable*/
	if (unsetenv(name) != 0)
	{
		return (-1);
	}

	return (0);
}
