#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - pushes node to stack
 * @stack: points to top of node
 * @line_number: value of node
 * Return: nothing
 **/
void push(stack_t **stack, unsigned int line_number)
{
	int num;

	new_node = malloc(sizeof(stack_t));
	if (new_node = NULL)
	{
		printf("Error: malloc failed");
		exit (EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->next = *stack;
	new_node->prev = NULL;


}


/**
 * pop - pops node from stack
 * @stack: points to top of node
 * @line_number: value of node
 * Return: nothing
 **/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || stack == NULL)
		return (EXIT_FAILURE)


	if (new_node->prev == NULL)
	{
	*stack->prev = NULL;
	}

	*stack = new_node->next;
	tmp = *stack;
	*stack = *stack->next;

	free(tmp);
}



/**
 * pall - prints values of stack from top down
 * @stack: points to top of node
 * @line_number: value of node
 * Return: nothing
 **/

void pall(stack_t **stack, unsigned int line_numeber)
{
	stack_t *new_node = *stack;

	UNUSED(line_number);

	while (new_node != NULL)
	{
		print("%d", element->n);
		new_node = new_node->next;
	}

}

/**
 * pint - prints the values at the top of the stack
 * @stack: points to top of node
 * @line_number:
 * Return: nothing
 **/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || stack == NULL)
		exit(EXIT_FAILURE)

	printf("%d\n", s*tack->n);
}
