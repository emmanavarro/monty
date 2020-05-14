#include "monty.h"
int number;
/**
 * execute_opcode - read, open and execute.
 * @argv: arguments
 */
void execute_opcode(char **argv)
{
	FILE *fp;
	char str[1000], *buff = NULL, *token = NULL;
	unsigned int line_number = 1;
	ssize_t line_size;
	size_t len = 0;
	void (*funct)(stack_t **stack, unsigned int line_number);
	stack_t *top = NULL;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		open_error(argv);
	while ((line_size = getline(&buff, &len, fp)) != EOF)
	{
		token = strtok(buff, " \t\n\r");
		if (token == NULL)
		{
			line_number += 1;
			continue;
		}
		strcpy(str, token);
		if (is_hash(token, line_number) == 1)
		{
			line_number += 1;
			continue;
		}
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " \t\n\r");
			if (token == NULL || is_number(token) == -1)
				not_int_error(line_number);
			number = atoi(token);
			funct = get_op_code(str, line_number), funct(&top, line_number);
		}
		else
		{
			funct = get_op_code(token, line_number), funct(&top, line_number);
		}
		line_number++;
	}
	fclose(fp);
}
