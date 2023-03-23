#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a newline
 *
 * @stack: a pointer to the head of a stack_t linked list
 * @line_number: the current line number of a bytecode file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	while (current->next)
		current = current->next;

	if (current->n < 0 || current->n > 177)
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			exit(EXIT_FAILURE);
		}

	printf("%c\n", current->n);
}
