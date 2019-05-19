#include "monty.h"

void print_file(FILE *input_file);
void (*get_func(char *op))(stack_t **stack, unsigned int line_number);
char **token_maker(char *str);
void run_function(char *opcode, unsigned int op, stack_t **stack, unsigned int line_number);

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
	int operand;
	unsigned int line_count = 0;
	stack_t *new = NULL;


	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s file \n", argv[0]);
		exit(EXIT_FAILURE);
	}
	mfile = fopen(argv[1], "r");
	if (mfile == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while ((chars_read = getline(&line, &line_sz, mfile)) != -1)
	{
		sscanf(line, "%s %d", opcode, &operand);
		rax.data = operand;
		get_func(opcode)(&new, line_count);
		line_count++;
	}
	free(line);
	fclose(mfile);
	exit(EXIT_SUCCESS);
}



/**
 *
 *
 **/

void (*get_func(char *op))(stack_t **stack, unsigned int line_number)
{
	switch(op)
	{
	case "push":
		push();
	}
}




/*

void print_file(FILE *input_file)
{
	int letter;

	while ((letter = fgetc(input_file)) != '\n')
		printf("%c", letter);
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

/**
void (*get_func(char *op))(stack_t **stack, unsigned int line_number)
{
	instruction_t op_func[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{NULL, nop}
	};

	int i = 0;
	while (op_func[i].opcode)
	{
		if (*op == *op_func[i].opcode)
		{
			return(*op_func[i].f);
		}
		i++;
	}
	return (NULL);
}
*/

/**
 * token_maker - splits a string into an array of tokens
 * @str: string to be tokenized and packaged
 *
 * Return: vector array of string tokens
 */

/*
char **token_maker(char *str)
{
	size_t idx = 0, io = 0;
	int tkn = 1;
	char **tokens;
	char *buf, *token, *bufptr, *delim = " :\t";

	buf = strdup(str);
	if (buf == NULL)
		return (NULL);
	bufptr = buf;
	while (*bufptr)
	{
		if (strchr(delim, *bufptr) != NULL && io == 0)
		{
			tkn++;
			io = 1;
		}
		else if (strchr(delim, *bufptr) == NULL && io == 1)
			io = 0;
		bufptr++;
	}
	tokens = malloc(sizeof(char *) * (tkn + 1));
	token = strtok(buf, delim);
	while (token)
	{
		tokens[idx] = strdup(token);
		if (tokens[idx] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		idx++;
	}
	tokens[idx] = NULL;

	return (tokens);
}
*/
