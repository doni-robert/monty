#include "monty.h"

/**
 * malloc_fail - prints an error message upon malloc failure
 */

void malloc_fail()
{
	perror("Error: malloc failed");
	exit(EXIT_FAILURE);
}
