#include "monty.h"


/**
 * add - adds the top two elements of the stack
 * @stack: points to top of node
 * @line_number: value of node
 * Return: nothing
 **/
void add(stack_t **stack, unsigned int line_number)
{
	int a, b;

	if (rax.stack_sz < 2)
	{
		printf("L%u: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	pop(stack, rax.linenum);
	a = rax.popval;
	pop(stack, rax.linenum);
	b = rax.popval;
	rax.operand = a + b;
	push(stack, rax.linenum);
}


/**
 * sub - subtract the top two elements of the stack
 * @stack: points to top of node
 * @line_number: value of node
 * Return: nothing
 **/
void sub(stack_t **stack, unsigned int line_number)
{
	int i, j;

	if (rax.stack_sz < 2)
	{
		printf("L%u: can't sub, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	pop(stack, rax.linenum);
	i = rax.popval;
	pop(stack, rax.linenum);
	j = rax.popval;
	rax.operand = j - i;
	push(stack, rax.linenum);
}
