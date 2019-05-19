#include "monty.h"
/**
 * error_handling - handles errors
 * @n: tells me which error to run
 * Return: return if fail or success
 **/
int error_handling(int n)
{
	switch(n)
	{
	case 1:
		fprintf(stderr, "L%u: usage: push integer\n",global.line_num);
		break;
	case 2:
		fprintf(stderr, "L%u: can't pint, stack empty\n",global.line_num);
		break;
	case 3:
		fprintf(stderr, "L%u: can't pop an empty stack\n",global.line_num);
		break;
	case 4:
		fprintf(stderr, "L%u:  can't swap, stack too short\n",global.line_num);
		break;
	case 5:
		fprintf(stderr, "L%u: can't add, stack too short\n",global.line_num);
		break;
	case 6:
		fprintf(stderr, "L%u: can't sub, stack too short\n",global.line_num);
		break;
	case 7:
		fprintf(stderr, "L%u: division by zero\n",global.line_num);
		break;
	case 8:
		fprintf(stderr, "L%u: can't mul, stack too short\n",global.line_num);
		break;
	case 9:
		fprintf(stderr, "L%u: division by zero\n",global.line_num);
		break;
	case 10:
		fprintf(stderr, "L%u: can't pchar, value out of range\n",global.line_num);
		break;
	case 11:
		fprint(stderr, "L%u: can't pchar, stack empty\n", global.line_num);
		break;
	}


	exit(EXIT_FAILURE);
}
