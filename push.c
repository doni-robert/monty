#include "monty.h"

/**
 * push - pushes an element to the stack
 *
 * @stack: the stack of memory
 * @line_number: the line number of the line to be executed
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *temp;

	temp = *stack;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		perror("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (data == NULL)
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new->n = *data;
	new->next = NULL;
	if (stack == NULL)
		new->prev = NULL;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		new->prev = temp;
		temp->next = new;
	}
}

