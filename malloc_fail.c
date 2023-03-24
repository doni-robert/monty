#include "monty.h"

/**
 * malloc_fail - prints an error message upon malloc failure
 */

void malloc_fail(void)
{
	perror("Error: malloc failed");
	exit(EXIT_FAILURE);
}
