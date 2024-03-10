#include "shell.h"

/*
 * env_inbuilt - Implements the env built-in
 * @args: Array of argument strings
 */
void env_inbuilt(char **args)
{
    char **current;
    for (current = environ; *current; current++)
    {
        printf("%s\n", *current);
    }
}

/**
 * exit_inbuilt - Implements the exit built-in
 * @args: Array of argument strings
 */
void exit_inbuilt(char **args)
{
    exit(EXIT_SUCCESS);
}