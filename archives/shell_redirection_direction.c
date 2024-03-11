#include "shell.h"
/**
 * determine_redirection_direction - direction of the redirection
 * @user_argv: - Pointer to an array of  command and its arguments
 * @program_name: - name of program
 * Return: 1 output redirection, 0 input redirection,
 * -1 no redirection symbol found
 */
int determine_redirection_direction(char **user_argv, const char *program_name)
{
	(void)program_name;
	while (*user_argv != NULL)
	{
		if (strcmp(*user_argv, ">") == 0)
		{
			return (1);
		}
		else if (strcmp(*user_argv, "<") == 0)
		{
			return (0);
		}
		user_argv++;
	}
	return (-1);
}
