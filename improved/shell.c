#include "shell.h"

int main(int argc, char *argv[])
{
/* Create infinite loop for the prompt */
while(1)
{
    /*getline*/
    size_t size = 0;
    char  *pstring = NULL;
    /*prompt*/
    const char *prompt;
    ssize_t prompt_message;
    /*strtok*/
    char *token;


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
    if (getline(&pstring, &size, stdin) == -1)
    {
        perror("Error reading input");
        free(pstring);
        continue;
    }

    /* Remove the newline character (if present) */
    if (pstring[strlen(pstring) - 1] == '\n')
        pstring[strlen(pstring) - 1] = '\0';

    /* Parse User Input */
    /* Tokenize the input using space as the delimiter */
    
    token = strtok(pstring, " ");
    while (token != NULL)
    {
        token = strtok(NULL, " ");
    }

  

   


/* Free dynamically allocated memory */
free(pstring);
return (0);





/*Execute Commands*/
static char *newargv[] = {NULL};
static char *newenviron[] = {NULL};

if (argc != 2)
{
    fprintf(stderro, "Usage: %s <file-to-exec>\n", argv[0]);
    exit(EXIT_FAILURE);
}

newargv[0] = argv[1];

execve(argv[1], newargv, newenviron);
perror("execve");
exit(EXIT_FAILURE);
/*Handle EOF*/
/*Handle Path*/
/*Implement Built-in Commands*/
/*Support input/output Redirections*/
/*Support Pipes*/
/*Support Background Jobs*/
}





}
