#include "monty.h"
/**
 * get_op_code - contain the function that will perform the operation
 * @tok: operation code
 * @l: line readed
 * Return: void
 */
void (*get_op_code(char *tok, unsigned int l)) (stack_t **stack, unsigned int)
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
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{NULL, NULL}
	};
	for (i = 0; instruct_code[i].opcode != NULL; i++)
	{
		if (strcmp(tok, instruct_code[i].opcode) == 0)
		{
			return (instruct_code[i].f);
		}
	}
	inv_instruction_error(tok, l);
	return (NULL);
}
