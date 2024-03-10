#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char* read_input();
char* parse_input(char *pstring, char *args[]);
void execute_command(char *command, char *args[], char *pstring);
void env_inbuilt(char **args);
void exit_inbuilt(char **args);

#endif /* SHELL_H*/