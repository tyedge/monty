#include "monty.h"

/**
 * push - pushes node to stack
 * @stack: points to top of node
 * @line_number: value of node
 * Return: nothing
 **/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_node->n = line_number;
	new_node->next = *stack;
	new_node->prev = NULL;

}

/**
 * pop - pops node from stack
 * @stack: points to top of node
 * @line_number: value of node
 * Return: nothing
 **/
void pop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *temp;
	stack_t *new_node = *stack;

	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);

	if (new_node->prev == NULL)
	{
		(*stack)->prev = NULL;
	}

	*stack = new_node->next;
	temp = *stack;
	*stack = (*stack)->next;

	free(temp);
}
/**
 * pall - prints values of stack from top down
 * @stack: points to top of node
 * @line_number: value of node
 * Return: nothing
 **/

void pall(stack_t **stack, unsigned int line_numeber __attribute__((unused)))
{
	stack_t *new_node = *stack;

	while (new_node != NULL)
	{
		printf("%d", new_node->n);
		new_node = new_node->next;
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
	printf("%d\n", (*stack)->n);
}
