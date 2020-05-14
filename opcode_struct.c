#include "monty.h"
/**
 * get_op_code - contain the function that will perform the operation
 * @token: operation code
 * @line: line readed
 * Return: void
 */
void (*get_op_code(char *token, unsigned int line)) (stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t instruct_code[] = {
		{"push", _push_stack},
		{"pall", _pall_stack},
		{"pint", _pint_stack},
		{"pop", _pop_stack},
		{"swap", _swap},
		{"nop", _nop},
		{"add", _add},
		{NULL, NULL}
	};

	for (i = 0; instruct_code[i].opcode != NULL; i++)
	{
		if (strcmp(token, instruct_code[i].opcode) == 0)
		{
			return (instruct_code[i].f);
		}
	}
	inv_instruction_error(token, line);
	return (NULL);
}
