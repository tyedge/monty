#include "monty.h"


/**
 * push - pushes node to stack
 * @stack: points to top of node
 * @line_number: value of node
 * Return: nothing
 **/

void push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *top;
	rax.data = rax.operand;
	if (stack == NULL)
		return;
	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	top->n = rax.data;
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
	rax.head = top;
	rax.stack_sz++;
}


/**
 * pop - pops node from stack
 * @stack: points to top of node
 * @line_number: value of node
 * Return: nothing
 */

void pop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	current = *stack;
	*stack = (*stack)->next;
	rax.popval = current->n;
	rax.stack_sz--;
	current->next = NULL;
	rax.stack_sz--;
	free(current);
}


/**
 * pall - prints values of stack from top down
 * @stack: points to top of node
 * @line_number: value of node
 * Return: nothing
 **/

void pall(stack_t **stack __attribute__((unused)), unsigned int line_number __attribute__((unused)))
{
	stack_t *new_node = *stack;
	while (new_node != NULL)
	{
		printf("%d\n", new_node->n);
		new_node = new_node->next;
	}

}


/**
 * pint - prints the values at the top of the stack
 * @stack: points to top of node
 * @line_number: line number
 * Return: nothing
 **/

void pint(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);
	printf("%d\n", (*stack)->n);
}


/**
 * swap - pushes node to stack
 * @stack: points to top of node
 * @line_number: value of node
 * Return: nothing
 **/

void swap(stack_t **stack, unsigned int line_number)
{
	int c, d;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	pop(stack, rax.linenum);
	c = rax.popval;
	pop(stack, rax.linenum);
	d = rax.popval;
	rax.operand = c;
	push(stack, rax.linenum);
	rax.operand = d;
	push(stack, rax.linenum);
}
