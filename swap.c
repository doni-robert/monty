#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 *
 * @stack: a pointer to the head of a stack_t linked list
 * @line_number: the current line number of a bytecode file
 */
void swap(stack_t **stack, unsigned int line_number)
{       
        stack_t *current, *previous;
	int temp, count;
        
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
                fprintf(stderr, "L%d: can't swap, stack too short", line_number);
                exit(EXIT_FAILURE);
        }
	temp = previous->n;
	previous->n = current->n;
	current->n = temp;
}

