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
	int line_number = 0;
	char *cmd, *buf, *arg;
	void (*fptr)(stack_t **stack, unsigned int line_number);
	stack_t **stack;
	FILE *fd;

	stack = malloc(sizeof(stack_t *) * 100);
	*stack = malloc(sizeof(stack_t) * 100);

	buf = malloc(sizeof(char) * 100);
	buf[0] = '\0';

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
	
	while(fgets(buf, 100, fd) != NULL)
	{
		if (100 - strlen(buf) < sizeof(buf))
		{
			_realloc(buf, 100, 200);
		}

		line_number++;
		cmd = strtok(buf, " ");
		if (cmd[0] == '#')
			continue;

		arg = strtok(NULL, " ");
		if (arg == NULL)
		{
			cmd[strlen(cmd) - 1] = '\0';
			data = 0;
		}
		else
			data = atoi(arg);
		
		fptr = get_op(cmd);
		if (fptr == NULL)
		{
			fprintf(stderr, "L%i: unknown instruction %s", line_number, cmd);
			exit(EXIT_FAILURE);
		}
		fptr(stack, line_number);
	}
	fclose(fd);
	return (1);
}


