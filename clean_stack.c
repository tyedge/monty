#include "monty.h"

/**
 * free_nodes - frees memory allocated for dlistint
 * objects
 * @head: a pointer to a pointer to a dlistint_t linked list
 *
 * Return: void
 *
 */

void free_nodes(stack_t *head)
{
	if (head == NULL)
		return;
	while (head->next != NULL)
	{
		head = head->next;
		free(head->prev);
	}
	free(head);
}


/**
 * nop - does nothing
 * @stack: points to top of stack
 * @line_number: value of node
 * Return: Nothing
 */
void nop(stack_t **stack __attribute__((unused)), unsigned int line_number
	 __attribute__((unused)))
{
}
