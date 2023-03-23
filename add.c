#include "monty.h"

/**
 * add - adds the top two elements of the stack
 *
 * @stack: a pointer to the head of a stack_t linked list
 * @line_number: the current line number of a bytecode file
 */
void add(stack_t **stack, unsigned int line_number)
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
                fprintf(stderr, "L%d: can't add, stack too short", line_number);
                exit(EXIT_FAILURE);
        }
	previous->n += current->n;
	previous->next = NULL;
	free(current);
}


