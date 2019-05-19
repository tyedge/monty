#include "monty.h"

int main(void)
{
	stack_t *oth = NULL;
	unsigned int line_count = 1;

	rax.data = 2;

	oth = malloc(sizeof(stack_t));
	if (oth == NULL)

	oth->n = rax.data;

	rax.data = 1;
	push(&oth, line_count);

	rax.data = 2;
	push(&oth, line_count);

	rax.data = 3;
	push(&oth, line_count);

	pall(&oth, line_count);
	add(&oth, line_count);
	pall(&oth, line_count);

	return (0);

}


 /** 38 * add - adds the top two elements of the stack
  * @stack: points to top of node
  * @line_number: value of node  * Return: nothing
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
