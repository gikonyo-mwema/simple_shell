#include "shell.h"

/**
 * execute_command - Execute the command
 * @command: Pointer to the command string
 * @args: Array of argument strings
 * @pstring: Pointer to the input string
*/
void execute_command(char *command, char *args[], char *pstring)
{
    char *path;
    char exec_path[1024];
    struct stat stats;
    char *command;
    char *path_dir;
    pid_t pid;

    if (strcmp(command, "env") == 0)
    {
        env_inbuilt(args);
        free(pstring);
        continue;
    }
    else if (strcmp(command, "exit") == 0)
    {
        exit_builtin(args);
        free(pstring);
        continue;
    }
    /* Parsing the PATH */
    path = getenv("PATH");
    if (path == NULL)
    {
        perror("Error getting PATH");
        free(pstring);
        continue;
    }
    path_dir = strtok(path, ":");
    while(path_dir != NULL)
    {
        sprintf(exec_path, "%s/%s", path_dir, command);
        if(stat(exec_path, &stats) == 0)
        {
            printf("Executable found at %s\n", exec_path);
            break;
        }
        path_dir = strtok(NULL, ":");
    }

    if (path_dir == NULL)
    {
        printf("Command not found\n");
        free(pstring);
        continue;
    }

    pid = fork();
    if(pid < 0)
    {
        perror("Error forking");
        free(pstring);
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        if (execve(exec_path, args, environ) == -1)
        {
            perror("Error executing command");
            exit(EXIT_FAILURE);
        }          
    }
    else
    {
        int status;
        wait(&status);
    }
    free(pstring);
}
  