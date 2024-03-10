#include "shell.h"

/**
 * run_command - Run the command
 * @exec_path: The executable path
 * @args: Array of argument strings
 * @pstring: Pointer to the input string
 */
void run_command(char *exec_path, char *args[], char *pstring)
{
    pid_t pid = fork();
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