#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char* read_input();
char* parse_input(char *pstring, char *args[]);
void execute_command(char *command, char *args[], char *pstring);
char* find_executable(char *path, char *exec_path, char *command, struct stat *stats);
void run_command(char *exec_path, char *args[], char *pstring);
void env_inbuilt(char **args);
void exit_inbuilt(char **args);
void error_handling(const char *msg);
void free_memory(char *pstring);

#endif /* SHELL_H*/
