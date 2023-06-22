#include "monty.h"
global_var var_global;
/**
 * main - main function program
 * @ac: first argument
 * @av: operation file
 * Return: 0
 */
int main(int ac, char **av)
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	open_file(av[1], &stack);
	release_list(stack);
	return (0);
}
