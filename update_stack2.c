#include "monty.h"

/**
 * sq_pstr - mod function
 * @stack: pointer arg
 * @line_num: number of line(s)
 */
void sq_pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;
	int c = 0;

	(void)line_num;


	while (tmp)
	{
		c = tmp->n;
		if (c == 0 || sq_isalpha(c) == 0)
			break;
		putchar(c);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * sq_rotl - mod function
 * @stack: pointer arg
 * @line_num: number of line(s)
 */
void sq_rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *runner = *stack;


	int aux1 = 0;

	if (!line_num || !stack || !*stack || !(*stack)->next)
		return;

	aux1 = runner->n;

	while (runner->next)
	{
		runner = runner->next;
		runner->prev->n = runner->n;
	}

	runner->n = aux1;
}

/**
 * sq_rotr - mod functions
 * @stack: pointer arg
 * @line_num: number of line(s)
 */
void sq_rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *runner = *stack;

	int aux1 = 0;

	if (!line_num || !stack || !*stack || !(*stack)->next)
		return;

	while (runner->next)
		runner = runner->next;

	aux1 = runner->n;

	while (runner->prev)
	{
		runner = runner->prev;
		runner->next->n = runner->n;
	}

	runner->n = aux1;
}
