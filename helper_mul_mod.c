#include "monty.h"

/**
 * mul - multiply the top two elements of the stack
 * @stack: points to top of node
 * @line_number: value of node
 * Return: nothing
 **/
void mul(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't multiply, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n *= tmp;
}
