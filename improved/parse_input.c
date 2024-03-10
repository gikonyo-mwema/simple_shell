#include "shell.h"

/**
 * parse_input - Parse the input string
 * @pstring: Pointer to the input string
 * @args: Array of argument string
 * 
 * Return: Pointer to the command string
*/
char *parse_input(char *pstring, char *args[])
{
    char *token;
    int i = 0;

    /* Tokenize the input using space as the delimiter */        
    token = strtok(pstring, " ");
    while (token != NULL)
    {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    return (args[0]);
}