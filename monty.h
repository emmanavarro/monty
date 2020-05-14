#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

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


void _push_stack(stack_t **top, unsigned int line_number);
void _pall_stack(stack_t **top, unsigned int line_number);
void _free_stack(stack_t *top);
void _pint_stack(stack_t **top, unsigned int line_number);
void _pop_stack(stack_t **top, unsigned int line_number);
void _swap(stack_t **top, unsigned int line_number);
void _add(stack_t **top, unsigned int line_number);
void _nop(stack_t **top, unsigned int line_number);


void (*get_op_code(char *tok, unsigned int l)) (stack_t **stack, unsigned int);
void execute_opcode(char **argv);

void malloc_error(void);
void arguments_error(void);
void open_error(char **argv);
void inv_instruction_error(char *instruction, unsigned int line);
void not_int_error(unsigned int line);

void pint_error(unsigned int line);
void pop_error(unsigned int line);
void swap_error(unsigned int line);
void add_error(unsigned int line);
void sub_error(unsigned int line);

int is_number(char *token);
int is_hash(char *token, int line_count);

#endif
