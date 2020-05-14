#include "monty.h"
/**
 * main - main of the program.
 * @argv: arguments
 * @argc: integer value
 * Return: 0 success
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		arguments_error();
	execute_opcode(argv);
	return (0);
}
