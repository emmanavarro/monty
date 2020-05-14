#include "monty.h"
int number;

/**
 * _push_stack - push a node to a list.
 *Description: Function that push a new node at the beginning of stack_t stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void _push_stack(stack_t **top, unsigned int line_number)
{
	stack_t *new;

	(void) line_number;
	new = malloc(sizeof(stack_t));
	
	if (new == NULL)
		malloc_error();

	new->n = number;
	new->prev = NULL;
	if (*top == NULL)
	{
		new->next = NULL;
		*top = new;
	}
	else
	{
		new->next = *top;
		(*top)->prev = new;
		*top = new;
	}
}
/**
 * _pall_stack - print elements in stack.
 * Description: Function that print the elements of a stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void _pall_stack(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = *top;
	(void)line_number;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * _free_stack - free list.
 * Description: Function that frees a dlist_t list
 * @top: top of the stack (head)
 * Return: void
 **/
void _free_stack(stack_t *top)
{
	stack_t *temp;

	if (top == NULL)
		return;

	while (top != NULL)
	{
		temp = top;
		top = top->next;
		free(temp);
	}
	free(top);
}
/**
 * _pint_stack - print top value.
 * Description: Function that print the value at the top of stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void _pint_stack(stack_t **top, unsigned int line_number)
{
	stack_t *tmp = *top;

	if (tmp != NULL)
		printf("%d\n", tmp->n);
	else
		pint_error(line_number);
}
/**
 * _pop_stack - delete top value of stack.
 * Description: Function that pop the value at top of stack
 * @top: element at the top of the stack (head)
 * @line_number: constant int value in the structure
 * Return: void
 **/
void _pop_stack(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *top;
	if (*top == NULL)
		pop_error(line_number);

	tmp = tmp->next;
	free(*top);
	*top = tmp;
}