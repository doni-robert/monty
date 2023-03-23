#include "monty.h"

/**
 * pall - prints all the values on the stack starting from the top of the stack
 *
 * @stack: pointer to the stack
 * @line_number: the number of the line on the file the command was read from
 */

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		printf("%i\n", temp->n);
		temp = temp->prev;
	}
}
