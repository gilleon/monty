#include "monty.h"
/**
 * open_file - reads a bytecode file and runs commands
 * @filename: pathname to file
 * @stack: pointer to the top of the stack
 */
void open_file(char *filename, stack_t **stack)
{
	char *line;
	size_t i = 0;
	int line_count = 1;
	instruct_func s;
	int check;
	int read;


	var_global.file = fopen(filename, "r");

	if (var_global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&var_global.buffer, &i, var_global.file)) != -1)
	{
		line = scan_line(var_global.buffer, stack, line_count);
		if (line == NULL || line[0] == '#')
		{
			line_count++;
			continue;
		}
		s = get_op_func(line);
		if (s == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, line);
			exit(EXIT_FAILURE);
		}
		s(stack, line_count);
		line_count++;
	}
	free(var_global.buffer);
	check = fclose(var_global.file);
	if (check == -1)
		exit(-1);
}

/**
 * get_op_func -  fnc to check operator
 * @str: the arg passed
 * Return: returns a functions, or NULL if failed
 */
instruct_func get_op_func(char *str)
{
	int x;

	command_t instruct[] = {
		{"push", sq_push},
		{"pall", sq__pall},
		{"pint", sq_pint},
		{"pop", sq_pop},
		{"swap", sq_swap},
		{"add", sq_add},
		{"nop", sq_nop},
		{"sub", sq_sub},
		{"mul", sq_mul},
		{"div", sq_div},
		{"mod", sq_mod},
		{"pchar", sq_pchar},
		{"pstr", sq_pstr},
		{"rotl", sq_rotl},
		{"rotr", sq_rotr},
		{NULL, NULL},
	};

	x = 0;
	while (instruct[x].f != NULL && strcmp(instruct[x].opcode, str) != 0)
	{
		x++;
	}

	return (instruct[x].f);
}

/**
 * isnumber - function for number check
 * @str: string checked
 * Return: returns 1 if value parsed is a number else 0
 */
int isnumber(char *str)
{
	unsigned int x;

	if (str == NULL)
		return (0);
	x = 0;
	while (str[x])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[x]))
			return (0);
		x++;
	}
	return (1);
}

/**
 * scan_line - parses a line for an opcode and arguments
 * @line: the line to be parsed
 * @stack: pointer to the head of the stack
 * @line_num: the current line number
 * Return: returns the opcode or null on failure
 */
char *scan_line(char *line, stack_t **stack, unsigned int line_num)
{
	char *op_code, *push, *arg;
	(void)stack;

	push = "push";
	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);

	if (strcmp(op_code, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (isnumber(arg) == 1 && arg != NULL)
		{
			var_global.inject = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}