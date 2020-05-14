#include "monty.h"
int number;

/**
 * main - main of the program.
 * @argv: arguments
 * @argc: integer value
 * Return: 0 success
 */

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char str[MAXCHAR];
	char *filename = argv[1], *line = NULL, *token = NULL;
	unsigned int line_number = 1;
	void (*funct)(stack_t **stack, unsigned int line_number);
	stack_t *top = NULL;

	if (argc != 2)
		arguments_error();

	fp = fopen(filename, "r");
	if (fp == NULL)
		open_error(argv);

	while ((line = fgets(str, MAXCHAR, fp)) != NULL)
	{
		token = strtok(line, " \t\n\r");
        if (token == NULL)
			continue;
		strcpy(str, token);
        if (strcmp(token, "push") == 0)
		{	
    	    token = strtok(NULL, " \t\n\r");
			if (token == NULL || is_number(token) == -1)
				not_int_error(line_number);
			number = atoi(token);
			funct = get_op_code(str, line_number);
			funct(&top, line_number);
		}
		else
		{
			funct = get_op_code(token, line_number);
			funct(&top, line_number);
		}
		line_number++;
		//printf("%s", tk);
	}
	_free_stack(top);
	fclose(fp);
	return (0);
}
