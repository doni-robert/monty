#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 *
 * @stack: stack of memory
 * @line_number: the line number of the read byte code
 * Return: nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;
	printf("%i\n", temp->n);
}
