#include "monty.h"
/**
 * main - main of the program.
 * @argv: arguments
 * @argc: integer value
 * Return: 0 success
 */
int main(int argc, char **argv)
{
	char *buff = NULL;
	stack_t *top = NULL;

	if (argc != 2)
		arguments_error();
	execute_opcode(argv);
	if (buff != NULL)
		free(buff);
	_free_stack(top);

	return (0);
}
