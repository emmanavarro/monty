#include "monty.h"
/**
 * sub_error - error if the stack contains less than two elements
 * @line: line
 * Return: void
 */
void sub_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't sub, stack too short\n", line);
	exit(EXIT_FAILURE);
}
/**
 * div_error - error if the stack contains less than two elements
 * @line: line
 * Return: void
 */
void div_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't div, stack too short\n", line);
	exit(EXIT_FAILURE);
}
/**
 * div2_error - error if the top element of the stack is 0
 * @line: line
 * Return: void
 */
void div2_error(unsigned int line)
{
	fprintf(stderr, "L%u: division by zero\n", line);
	exit(EXIT_FAILURE);
}
/**
 * mul_error - error if the stack contains less than two elements
 * @line: line
 * Return: void
 */
void mul_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't mul, stack too short\n", line);
	exit(EXIT_FAILURE);
}
/**
 * mod_error - error if the stack contains less than two elements
 * @line: The function´s parameter
 * Return: void
 */
void mod_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't mod, stack too short\n", line);
	exit(EXIT_FAILURE);
}
