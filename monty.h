#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdbool.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct global - struct of random things to be manipulated
 * @data: the n value of the stack struct
 * @head: pointer to head
 * @stack_sz: stack size
 * @funcs: operator functions
 * @opcode: opcode instruction
 * @operand: operand value
 * @popval: most recent value removed from stack
 * @linenum: global line number variable
 * @index: index of function to be run
 *
 * Description: random struct
 *
 */
struct global
{
        int data;
	stack_t *head;
	int stack_sz;
	char **funcs;
	char *opcode;
	int operand;
	int popval;
	unsigned int linenum;
	int index;
} rax;




struct finder
{

	char *instruction;
	int case_num;
};






void (*get_func(char *op))(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_numeber);
void pint(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void free_nodes(stack_t *head);

#endif /* MONTY_H */
