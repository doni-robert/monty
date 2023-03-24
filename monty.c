#include "monty.h"

/**
 * main - interprets monty byte code files
 *
 * @argc: argument count
 * @argv: argument vector
 */
int data;

int main(int argc, char **argv)
{
	stack_t **stack;
	FILE *fd;
	char **cmd;

	stack = malloc(sizeof(stack_t *) * 100);
	if (stack == NULL)
		malloc_fail();

	*stack = malloc(sizeof(stack_t) * 100);
	if (*stack == NULL)
		malloc_fail();

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}


	cmd = read(fd);
	exec(cmd, stack);

	return (1);
}
