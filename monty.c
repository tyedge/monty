#include "monty.h"

void print_file(FILE *input_file);
void (*get_func (char *op))(stack_t **stack, unsigned int line_number);
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
	int i = 0;
	unsigned int line_count = 0;
	stack_t *new = NULL;
	char *functions[8] = {"push", "pop", "pall", "pint", "swap", "add", "nop", NULL};

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s file \n", argv[0]);
		exit(EXIT_FAILURE);
	}
	mfile = fopen(argv[1], "r");
	if (mfile == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	else
	{
		while ((chars_read = getline(&line, &line_sz, mfile)) > -1)
		{
			sscanf(line, "%s %d", opcode, &operand);
			line_count++;
			rax.linenum = line_count;
			rax.opcode = opcode;
			/*rax.operand = operand;*/
			while (functions[i])
			{
				if (strcmp(rax.opcode, functions[i]) == 0)
				{
/*					printf("opcode is: %s\n", opcode);
					printf("match\n");*/
					if (strcmp(opcode, "pall") == 0 || strcmp(opcode, "pint") == 0)
					{
/*						printf("The instruction is: %s\n", rax.opcode);*/
						rax.operand= operand;
					}
					else
					{
						rax.operand= operand;
/*						printf("The instruction is: %s %d\n", rax.opcode, rax.operand);*/
					}
/*					printf("i in main is: %d\n", i);*/
					rax.index = i;
					get_func(rax.opcode)(&new, line_count);
					break;
					/*pall(&new, line_count);*/
				}
				i++;
			}
			i = 0;
		}
/*		rax.opcode = opcode;
		rax.data = operand;*/
		/*	push(&new, line_count);
		pint(&new, line_count);
		push(&new, line_count);
		pint(&new, line_count);
		push(&new, line_count);
		pint(&new, line_count);
		(get_func(opcode))(&new, line_count);*/
	}
/*	while (new)
	{
      		printf("%d\n", new->n);
       		new = new->next;
		}*/
	line_count = 0;
	free(line);
	free_nodes(new);
	fclose(mfile);
	return (0);
}


void print_file(FILE *input_file)
{
	int letter;

	while ((letter = fgetc(input_file)) != EOF)
		printf("%c", letter);
}

/**
 * get_func - function which takes a char pointer
 * argument and returns a pointer to a function
 * which takes a ** to a stack struct and an unsigned
 * int and returns void
 * an integer
 * : opcode instrunction passed from file
 *
 * Return: pointer to the function matching the
 * given opcode, if found, OR NULL
 *
 */
void (*get_func(char *op))(stack_t **stack, unsigned int line_number)
{

/*	if (strcmp(rax.opcode, "push") == 0)
		push(stack, line_number);
	if (strcmp(rax.opcode, "pall") == 0)
                pall(stack, line_number);
	if (strcmp(rax.opcode, "pop") == 0)
                pop(stack, line_number);
	if (strcmp(rax.opcode, "pint") == 0)
                pint(stack, line_number);
	if (strcmp(rax.opcode, "add") == 0)
                add(stack, line_number);
	if (strcmp(rax.opcode, "swap") == 0)
                swap(stack, line_number);
	if (strcmp(rax.opcode, "nop") == 0)
	nop(stack, line_number);*/

	instruction_t op_func[] = {
	       	{"push", push},
       		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
	};

	int i = rax.index;
/*	printf("The rax.opcode called is: %s\n", op);*/
	while (*op_func[i].opcode)
	{
/*		printf("i is: %d\n", i);*/
		if (*op != *op_func[i].opcode)
		{
			i++;
		}
		else
		{
/*			printf("Test val is: %d\n", 1);
			printf("The opcode to execute is: %s\n", op_func[i].opcode);*/
			return (*op_func[i].f);
		}
	}
	return (NULL);
}


/**
 * token_maker - splits a string into an array of tokens
 * @str: string to be tokenized and packaged
 *
 * Return: vector array of string tokens
 */

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
