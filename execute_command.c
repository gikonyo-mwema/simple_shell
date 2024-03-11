#include "shell.h"

/**
 * execute_command - Execute the command
 * @command: Pointer to the command string
 * @args: Array of argument strings
 * @pstring: Pointer to the input string
 *
 * Return: Exit status of the command
 */
int execute_command(char *command, char *args[], char *pstring)
{
    char *path, *path_dir;
    char exec_path[1024];
    struct stat stats;
    int exit_status = 0;

    /* Check for built-in commands */
    if (strcmp(command, "env") == 0)
    {
        env_inbuilt(args);
        free(pstring);
        return (exit_status);
    }
    else if (strcmp(command, "exit") == 0)
    {
        exit_inbuilt(args);
        free(pstring);
        return (exit_status);
    }
    else if (strcmp(command, "setenv") == 0)
    {
        setenv_builtin(args);
        free(pstring);
        return (exit_status);
    }
    else if (strcmp(command, "unsetenv") == 0)
    {
        unsetenv_builtin(args);
        free(pstring);
        return (exit_status);
    }
    else if (strcmp(command, "cd") == 0)
    {
        cd_builtin(args);
        free(pstring);
        return (exit_status);
    }

    /* Parsing the PATH */
    path = getenv("PATH");
    if (path == NULL)
    {
        perror("Error getting PATH");
        free(pstring);
        return (1);
    }

    /* Find the executable */
    path_dir = find_executable(path, exec_path, command, &stats);

    /* Execute the command */
    if (path_dir == NULL)
    {
        printf("Command not found\n");
        free(pstring);
        return (1);
    }

    exit_status = run_command(exec_path, args, pstring);

    return (exit_status);
}
