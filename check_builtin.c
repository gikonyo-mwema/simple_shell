#include "shell.h"

int check_builtin_commands(char *command, char *args[], char *pstring __attribute__((unused)))
{
	if (strcmp(command, "env") == 0)
	{
		env_inbuilt(args);
		return 1;
	}
	else if (strcmp(command, "exit") == 0)
	{
		exit_inbuilt(args);
		return 1;
	}
	else if (strcmp(command, "setenv") == 0)
	{
		setenv_inbuilt(args);
		return 1;
	}
	else if (strcmp(command, "unsetenv") == 0)
	{
		unsetenv_builtin(args);
		return 1;
	}
	else if (strcmp(command, "cd") == 0)
	{
		cd_builtin(args);
		return 1;
	}
	return 0;
}
