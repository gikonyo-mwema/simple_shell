#include "shell.h"

extern char **environ;

int main(int argc, char *argv[])
{
    /* Create infinite loop for the prompt */
    while(1)
    {
        char *psting = NULL;
        char *args[64];
        char *command;

        /* Prompt and Read input from the user */
        pstring = read_input();

        /* Parse User Input */
        command = parse_input(pstring, args);

        /* Execute the command */
        execute_command(command, args, pstring);
    }
    return (0);
} 


void error_handling(const char *msg)
{
    perror(msg);
}

void free_memory(char *pstring)
{
    if (pstring != NULL)
    {
        free(pstring);
    }
}