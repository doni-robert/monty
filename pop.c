#include "monty.h"

/**
 * pop - removes the top element of the stack
 *
 * @stack: a pointer to the head of a stack_t linked list
 * @line_number: the current line number of a bytecode file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *previous;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	current = previous = *stack;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	previous->next = NULL;
	free(current);
}


