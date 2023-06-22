#include "monty.h"

/**
 * sq_swap - swap function
 * @stack: pointer arg
 * @line_num: number of line(s)
 */

void sq_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *runner;
	int tmp;

	runner = *stack;
	if (runner == NULL || runner->next == NULL)
	{
		fprintf(stderr, "L%d: wait a min, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = runner->n;
	runner->n = runner->next->n;
	runner->next->n = tmp;
}

/**
 * sq_add - add function
 * @stack: pointer arg
 * @line_num: number of line(s)
 */

void sq_add(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;
	int sum = 0, i = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: wait a min, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}

	if (stack == NULL || (*stack)->next == NULL || i <= 1)
	{
		fprintf(stderr, "L%d: wait a min, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	sq_pop(stack, line_num);

	(*stack)->n = sum;
}
