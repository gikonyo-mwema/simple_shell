#include "shell.h"

/**
 * free_memory - Frees allocated memory
 * @pstring: Pointer to the memory to free
 */
void free_memory(char *pstring)
{
	if (pstring != NULL)
	{
		free(pstring);
	}
}
