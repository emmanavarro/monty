#include "monty.h"

/**
 * _pchar - main entry.
 * Description: Prints the char at the top of the stack
 * @top: element at the top of the stack
 * @line_number: constant int value in the structure
 * Return: void
 **/
void _pchar(stack_t **top, unsigned int line_number)
{
	int ascii_n;

	if (*top == NULL)
		pchar2_error(line_number);

	ascii_n = (*top)->n;

	if (ascii_n < 0 || ascii_n > 127)
		pchar_error(line_number);
	putchar(ascii_n);
	putchar('\n');
}

/**
 * _pstr -main entry
 * Description: prints the string starting at the top of the stack.
 * @top: element at the top of the stack (head)
 * @line_number: line
 * Return: void
 */
void _pstr(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;
	int ascii_n;

	(void)line_number;
	if (*top == NULL)
	{
		putchar('\n');
		return;
	}
	tmp = *top;
	while (tmp != NULL)
	{
		ascii_n = tmp->n;

		if (ascii_n <= 0 || ascii_n > 127)
			break;
		putchar(ascii_n);
		tmp = tmp->next;
	}
	putchar('\n');
}
