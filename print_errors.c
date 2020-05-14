#include "monty.h"
/**
 * pchar_error - main entry
 * Description: error message if the value is not in the ascii table
 * @line: The function's parameter
 * Return: void
 */
void pchar_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line);
	exit(EXIT_FAILURE);
}

/**
 * pchar2_error - error message if the stack is empty
 * @line: The function's parameter
 * Return: void
 */
void pchar2_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
	exit(EXIT_FAILURE);
}
