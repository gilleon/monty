#include "monty.h"
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


