#include "shell.h"
/**
* get_location - generate the path for each command
* @command: A pointer to a string representing the command to be located.
* Return: string containing the full path to the command if found,
* or NULL if the command is not found.
*/
char *get_location(char *command)
{
char *path = NULL;
char *path_env = getenv("PATH");
char *token, *full_path;

if (command == NULL || *command == '\0')
return (NULL);
if (strchr(command, '/') != NULL)
{
if (access(command, X_OK) == 0)
{
return (strdup(command));
}
return (NULL);
}
path = strdup(path_env);
if (path == NULL)
return (NULL);
token = strtok(path, ":");
while (token != NULL)
{
full_path = malloc(strlen(token) + strlen(command) + 2);
if (full_path == NULL)
{
free(path);
return (NULL);
}
strcpy(full_path, token);
strcat(full_path, "/");
strcat(full_path, command);

if (access(full_path, X_OK) == 0)
{
free(path);
return (full_path);
}
free(full_path);
token = strtok(NULL, ":");
}
free(path);
return (NULL);
}
