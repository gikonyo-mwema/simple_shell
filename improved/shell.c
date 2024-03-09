#include "shell.h"

extern char **environ;

int main(int argc, char *argv[])
{
    /* Create infinite loop for the prompt */
    while(1)
    {
        /*getline*/
        size_t size = 0;
        char  *pstring = NULL;
        ssize_t getline_status;
        /*prompt*/
        const char *prompt;
        ssize_t prompt_message;
        /*strtok*/
        char *token;
        char *args[64];
        int i = 0;
        /* PATH */
        char *path;
        char exec_path[1024];
        struct stat stats;
        char *command;
        char *path_dir;
        pid_t pid;


        /* Prompt */
        prompt = "$ ";

        /* Write the prompt to stdout */
        prompt_message = write(1, prompt, strlen(prompt));
        if (prompt_message == -1)
        {
            perror("Error writing to stdout");
            continue;
        }
   
        /* Read input form the user */
        getline_status = getline(&pstring, &size, stdin);
        if (getline_status == -1)
        {
            /* Check for EOF */
            if (feof(stdin))
            {
                write(1, "\n", 1);
                free(pstring);
                exit(EXIT_SUCCESS);
            }
            else
            {
                perror("Error reading input");
                free(pstring);
                continue;
            }
        }

        /* Remove the newline character (if present) */
        if (pstring[strlen(pstring) - 1] == '\n')
            pstring[strlen(pstring) - 1] = '\0';

        /* Parse User Input */
        /* Tokenize the input using space as the delimiter */        
        token = strtok(pstring, " ");
        while (token != NULL)
        {
            args[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;
        command = args[0];
  

        /* Parsing the PATH */
        path = getenv("PATH");
        if (path == NULL)
        {
            perror("Error getting PATH");
            free(pstring);
            continue;
        }

        /* Execute the command */
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
    return (0);
} 

/*Implement Built-in Commands*/
/*Support input/output Redirections*/
/*Support Pipes*/
/*Support Background Jobs*/

/* Free dynamically allocated memory */
free(pstring);
return (0);
}