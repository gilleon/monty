#include "monty.h"
/**
 * sq_push - push int to a stack
 * @stack: linked lists for
 * @line_num: number of line(s)
 */
void sq_push(stack_t **stack, __attribute__ ((unused))unsigned int line_num)
{
	stack_t *top;
	(void)line_num;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = var_global.inject;
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

/**
 * sq__pall - print all function
 * @stack: pointer arg
 * @line_num: number of line(s)
 */
void sq__pall(stack_t **stack, __attribute__ ((unused))unsigned int line_num)
{
	stack_t *runner;

	runner = *stack;
	while (runner != NULL)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}

/**
 * sq_pint - print int a top of stack
 * @stack: pointer arg
 * @line_num: number of line(s)
 *
 */
void sq_pint(stack_t **stack, unsigned int line_num)
{
	stack_t *runner;

	runner = *stack;
	if (runner == NULL)
	{
		fprintf(stderr, "L%d: wait a min, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", runner->n);
}

/**
 * sq_pop - remove element a list
 *@stack: pointer to first node
 *@line_num: integer
 *Return: void
 */
void sq_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *nodo = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: hold on, can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	*stack = nodo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(nodo);
}

/**
 * release_list - free a list
 * @head: pointer to first node
 *
 */
void release_list(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
