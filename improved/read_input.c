 #include "shell.h"
 
 /**
  * read_input - Reads the input from the user
  * 
  * Return: Pointer to the input string
  */
 char *read_input()
 {
    size_t size = 0;
    char  *pstring = NULL;
    ssize_t getline_status;
    const char *prompt;
    ssize_t prompt_message;

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

    return (pstring);

}