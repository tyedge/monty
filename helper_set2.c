#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * nop - does nothing
 * @stack: points to top of stack
 * @line_number: value of node
 * Return: Nothing
 **/
void nop(stack_t **stack __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{

}

/**
 * swap - pushes node to stack
 * @stack: points to top of node
 * @line_number: value of node
 * Return: nothing
 **/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->prev == NULL)
	{
		error_handling(4);
	}

	tmp = (*stack)->n;
	*stack->n = (*stack)->next->n;
	(*stack)->next->n = tmp;

}

/**
 * add - adds the top two elements of the stack
 * @stack: points to top of node
 * @line_number: value of node
 * Return: nothing
 **/
int add(stack_t **stack, unsigned int line_number __attribute__ ((unused)))
{
	int a = 0;
	int b = 0;

	stack_t **top = stack;

	if (stack_size < 2)
	{
		error_handling(5);
	}

	a = pop(top);
	b = pop(top);
	push(top, b + a);


	return (0);

}
/**
	int *tmp;
	(*stack)->n;
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n += tmp;
}

**/





/**
 * sub - subtract the top two elements of the stack
 * @stack: points to top of node
 * @line_number: value of node
 * Return: nothing
 **/
void sub(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't sub, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n -= tmp;
}


/**
 * div - divide the top two elements of the stack
 * @stack: points to top of node
 * @line_number: value of node
 * Return: nothing
 **/
void div(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't divide, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	if (tmp == 0)
	{
		printf("L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}


	(*stack)->n /= tmp;
}
