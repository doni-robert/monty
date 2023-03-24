#include "monty.h"

/**
 *
 *
 *
 */

void exec(char **cmd, stack_t **stack)
{
	int line_number, i;
	void (*fptr)(stack_t **stack, unsigned int line_number);

	i = 0;
	while (cmd[i] != NULL)
	{
		fptr = get_op(cmd[i]);
                if (fptr == NULL)
                {
                        fprintf(stderr, "L%i: unknown instruction %s\n", line_number, cmd[i]);
                        exit(EXIT_FAILURE);
                }
	
		line_number = i + 1;
                fptr(stack, line_number);
		i++;
        }
}
