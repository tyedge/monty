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
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->prev = *stack;
	(*stack)->next = tmp->next;

}

/**
 * add - adds the top two elements of the stack
 * @stack: points to top of node
 * @line_number: value of node
 * Return: nothing
 **/
void add(stack_t **stack, unsigned int line_number)
{
	int tmp;
	(*stack)->n;
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n += tmp;
}


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
