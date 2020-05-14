#include "monty.h"

/**
 * arguments_error - Main entry
 * Description: print error if user doesn't give file or more valid arguments
 * Return: void
 **/
void arguments_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * open_error - Main entry
 * Description: print message if it's not possible to open the file
 * @argv: arguments received by main
 * Return: void
 **/
void open_error(char **argv)
{
	char *filename = argv[1];

	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}
/**
 * inv_instruction_error - Main entry
 * Description: print message if le to open the filehas an invalid instruction
 * @instruction: instruction
 * @line: line
 * Return: void
 **/
void inv_instruction_error(char *instruction, unsigned int line)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line, instruction);
	exit(EXIT_FAILURE);
}
/**
 * not_int_error - Main entry
 * Description: print message if parameter received is not integer
 * @line: line
 * Return: void
 **/
void not_int_error(unsigned int line)
{
	fprintf(stderr, "L%u: usage: push integer\n", line);
	exit(EXIT_FAILURE);
}
/**
 * malloc_error - Main entry
 * Description: print error message if can't malloc anymore
 * Return: void
 **/
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
