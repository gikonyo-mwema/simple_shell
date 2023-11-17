#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
/**
 * struct info - Structure to hold command information
 *
 * @argv: Array of strings containing command arguments
 * @status: Integer representing command execution status
 * @err_num: Integer representing any associated error number
 *
 * Description:
 * holds information related to a command,
 */
struct info
{
	char **argv;
	int status;
	int err_num;
};

typedef struct info info_t;

/*void execute_external_command(char **user_argv);*/
void handle_builtin_commands(char **user_argv, char *lineptr);
/*void execute_command(char *lineptr, const char *delim);*/
int is_builtin_command(const char *command);
void free_resources(char **user_argv, char *lineptr);

int _erratoi(const char *str);
int _myexit(info_t *info);
int _mycd(info_t *info);
int _myhelp(info_t *info);

void print_prompt(const char *prompt);
void _print_shell(const char *output);
char **parse_command(char *lineptr, const char *delim);
char *get_command(void);

char *allocate_env_output(char **env_p, char *lineptr, char **user_argv);
int process_command(char **user_argv, char *lineptr, char **env_p);

int create_pipe(int pipefd[2]);
void handle_child_processes(int pipefd[2], char **argv_1, char **argv_2);
void execute_pipe(char **argv_1, char **argv_2);
void setup_pipe(int pipefd[2], char **argv);
void execute_redirection(char **argv, char *file, int direction);
void setup_redirection(char **argv, char *file, int direction);
int execmd(char **argv);
void execute_child(char **argv, char *command);
/* improved */
void execute_external_command(char **user_argv, const char *program_name);
void execute_command(char *lineptr, const char *delim, const char *program_name);


void execute_redirection(char **argv, char *file, int direction);
void execute_pipe(char **argv_1, char **argv_2);

int execmd(char **argv);
char *get_location(char *command);
int stat(const char *pathname, struct stat *statbuf);
extern char **environ;

/*my_unsetev*/
int my_setenv(const char *name, const char *value, char *overwrite);
int my_unsetenv(const char *name);

ssize_t custom_getline(int fd, char **line);

int contains_redirection_or_pipe(char **user_argv, const char *program_name);
int contains_pipe(char **user_argv, const char *program_name);
char **extract_first_command(char **user_argv, const char *program_name);
char **extract_second_command(char **user_argv, const char *program_name);
char *extract_redirection_file(char **user_argv, const char *program_name);
int determine_redirection_direction(char **user_argv, const char *program_name);

#endif
