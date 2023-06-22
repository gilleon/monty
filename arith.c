#include "monty.h"

/**
 * sq_sub - function to substitute
 * @stack: pointer to list in stack
 * @line_num: nline number
 */
void sq_sub(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;
	int sub = 0, x = 0;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't substitute, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	while (tmp)
	{
		tmp = tmp->next;
		x++;
	}

	if (stack == NULL || (*stack)->next == NULL || x <= 1)
	{
		fprintf(stderr, "L%d: can't substitute, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	sq_pop(stack, line_num);

	(*stack)->n = sub;
}

/**
 * sq_mul - function for mul
 * @stack: pointer arg
 * @line_num: number of line(s)
 */
void sq_mul(stack_t **stack, unsigned int line_num)
{
	int x;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: wait a min, stack too short\n", line_num);
		free(var_global.buffer);
		fclose(var_global.file);
		release_list(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		x = (*stack)->n;
		sq_pop(stack, line_num);
		(*stack)->n *= x;
	}
}

/**
 * sq_div - function to divide stack
 * @stack: pointer arg
 * @line_num: number of line(s)
 */
void sq_div(stack_t **stack, unsigned int line_num)
{
	int x = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: wait a min, stack is too short\n", line_num);
		free(var_global.buffer);
		fclose(var_global.file);
		release_list(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: divisible by zero\n", line_num);
		free(var_global.buffer);
		fclose(var_global.file);
		release_list(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		x = (*stack)->n;
		sq_pop(stack, line_num);
		(*stack)->n /= x;
	}
}

/**
 * sq_mod - funtion for mod
 * @stack: pointer arg
 * @line_num: number of line(s)
 */
void sq_mod(stack_t **stack, unsigned int line_num)
{
	int x = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: wait a min, stack too short\n", line_num);
		free(var_global.buffer);
		fclose(var_global.file);
		release_list(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: divisible by zero\n", line_num);
		free(var_global.buffer);
		fclose(var_global.file);
		release_list(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		x = (*stack)->n;
		sq_pop(stack, line_num);
		(*stack)->n %= x;
	}
}
