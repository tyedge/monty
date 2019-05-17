#include "monty.h"

/**
 * push - pushes node to stack
 * @stack: points to top of node
 * @line_number: value of node
 * Return: nothing
 **/
void  push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *top;


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
 **/
void  pop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new_node = *stack;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	if (new_node->next != NULL)
	{
		(*stack)->prev = NULL;
	}
	new_node = *stack;
	rax.head = new_node->next;
	rax.data = new_node->n;
	*stack = new_node->next;
	rax.stack_sz--;
	free(new_node);
}



/**
 * pall - prints values of stack from top down
 * @stack: points to top of node
 * @line_number: value of node
 * Return: nothing
 **/

void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t **new_node = stack;

	(*new_node)->n = rax.data;
	while (*new_node != NULL)
	{
		printf("%d\n", (*new_node)->n);
		*new_node = (*new_node)->next;
	}

}

/**
 * pint - prints the values at the top of the stack
 * @stack: points to top of node
 * @line_number:
 * Return: nothing
 **/
void pint(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);
	(*stack)->n = rax.data;
	printf("%d\n", (*stack)->n);
}
