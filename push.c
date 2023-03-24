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

	printf("push line\n");
	temp = *stack;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	printf("push line\n");	
	if (!data)
	{
		fprintf(stderr, "L%i: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}

	new->n = (data);
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

