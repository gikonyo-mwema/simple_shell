#include "shell.h"

/**
 * error_handling - Prints an error message to stderr
 * @msg: The error message to print
 */
void error_handling(const char *msg)
{
	perror(msg);
}
