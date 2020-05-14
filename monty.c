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
	unsigned int ln = 1;
	ssize_t line_size;
	size_t len = 0;
	void (*funct)(stack_t **stack, unsigned int ln);
	stack_t *top = NULL;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		open_error(argv);
	while ((line_size = getline(&buff, &len, fp)) != EOF)
	{
		token = strtok(buff, " \t\n\r");
		if (token == NULL)
		{
			ln += 1;
			continue;
		}
		strcpy(str, token);
		if (is_hash(token, ln) == 1)
		{
			ln += 1;
			continue;
		}
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " \t\n\r");
			if (token == NULL || is_number(token) == -1)
				not_int_error(ln);
			number = atoi(token), funct = get_op_code(str, ln), funct(&top, ln);
		}
		else
			funct = get_op_code(token, ln), funct(&top, ln);
		ln++;
	}
	fclose(fp);
	if (buff != NULL)
		free(buff);
	_free_stack(top);
}
