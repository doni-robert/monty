#include "monty.h"

/**
 * monty_mod - computes the rest of the division of the second top element
 * of the stack by the top element
 *
 * @stack: a pointer to the head of a stack_t linked list
 * @line_number: the current line number of a bytecode file
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *previous;
	int count;

	current = previous = *stack;
	count = 0;
	while (current->next)
	{
		previous = current;
		current = current->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by 0\n", line_number);
		exit(EXIT_FAILURE);
	}

	previous->n %= current->n;
	previous->next = NULL;
	free(current);
}
