#include "shell.h"

char *allocate_env_output(char **env_p, char *lineptr, char **user_argv) {
    char *env = *env_p;
    char *env_output = NULL;
    size_t current_length = 0;
    size_t total_length = 0;

    while (env != NULL)
	{
        size_t env_length = strlen(env);
        size_t new_length = current_length + env_length + 2;

        char *temp = realloc(env_output, new_length);
        if (temp == NULL) {
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

int main(void) {
    char *prompt = "($) ";
    const char *delim = " \n";
    char *lineptr = NULL;

    while (1) {
        if (isatty(STDIN_FILENO)) {
            print_prompt(prompt);
        }

        lineptr = get_command();
        if (lineptr == NULL) {
            break;
        }

        execute_command(lineptr, delim);
    }

    return 0;
}

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


void execute_command(char *lineptr, const char *delim) {
    int i = 0;
    char *token = NULL;
    char **user_argv = parse_command(lineptr, delim);

    token = strtok(lineptr, delim);
    while (token != NULL) {
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

int is_builtin_command(const char *command) {
    if (strcmp(command, "exit") == 0 || strcmp(command, "env") == 0 ||
        strcmp(command, "setenv") == 0 || strcmp(command, "unsetenv") == 0) {
        return 1;
    }
    return 0;
}

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
