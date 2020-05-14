#include "monty.h"


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
	char *filename = argv[1];
	char *line = NULL;
	char *tk = NULL;
	unsigned int i = 0, line_number = 1;
	void (*funct)(stack_t **stack, unsigned int line_number);
	stack_t *top = NULL;

	if (argc != 2)
		arguments_error();

	fp = fopen(filename, "r");
	if (fp == NULL)
		open_error(argv);

	while (!feof(fp))
	{
		line = fgets(str, MAXCHAR, fp);
		tk = strtok(line, " \t\n\r"); //Primer token
        i = 0;

        while (tk != NULL && i < 2)
        {
    	    funct = get_op_code(tk, line_number);
			tk = strtok(NULL, " \t\n\r");
			funct(&top, line_number);
			i++;
		}
		line_number++;
		//printf("%s", tk);
	}
	_free_stack(top);
	fclose(fp);
	return (0);
}