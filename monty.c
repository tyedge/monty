#include "monty.h"

/**
 * main - This program operates as a simple shell
 * @argc: the number of command line arguments
 * @argv: pointer to an array of command line
 * arguments
 *
 * Return: Always 0
 *
 */

int main(int argc, char **argv)
{
	FILE *mfile;
	char *line = NULL;
	size_t line_sz = 0;
	ssize_t chars_read;
	char opcode[128];
	int operand, i = 0, retval;
	unsigned int line_count = 0;
	stack_t *new = NULL;
	char *functions[9] = {"push", "pop", "pall", "pint", "swap", "add",
			      "nop", "sub", NULL};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	mfile = fopen(argv[1], "r");
	if (mfile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	else
	{
		while ((chars_read = getline(&line, &line_sz, mfile)) > -1)
		{
			line_count++;
			rax.linenum = line_count;
			retval = sscanf(line, "%s %d", opcode, &operand);
			if (retval < 0)
			{
				free(line);
				exit(EXIT_FAILURE);
			}
			rax.opcode = opcode;
			while (functions[i])
			{
				if (strcmp(rax.opcode, functions[i]) == 0)
				{
					rax.operand = operand;
					rax.index = i;
					get_func(rax.opcode)(&new, line_count);
					break;
				}
				i++;
			}
			i = 0;
			free(line);
			line = NULL;
		}
	}
	line_count = 0;
	free(line);
	free_nodes(new);
	fclose(mfile);
	return (0);
}

/**
 * get_func - function which takes a char pointer
 * argument and returns a pointer to a function
 * which takes a ** to a stack struct and an unsigned
 * int and returns void
 * an integer
 * @op: opcode instrunction passed from file
 *
 * Return: pointer to the function matching the
 * given opcode, if found, OR NULL
 *
 */
void (*get_func(char *op))(stack_t **stack, unsigned int line_number)
{
	instruction_t op_func[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
	};
	int i = rax.index;

	while (*op_func[i].opcode)
	{
		if (*op != *op_func[i].opcode)
		{
			i++;
		}
		else
		{
			return (*op_func[i].f);
		}
	}
	return (NULL);
}
