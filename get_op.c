#include "monty.h"

/**
 * get_op - selects the operation to be performed
 *
 * @name: the string to be compared with opcode
 * Return: function pointer to corresponding function
 */

void (*get_op(char *name))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t instructs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", pchar},
		{NULL, NULL}
	};

	while (instructs[i].opcode != NULL)
	{
		if (strcmp(name, instructs[i].opcode) == 0)
			return (instructs[i].f);
		i++;
	}
	return (NULL);
}
