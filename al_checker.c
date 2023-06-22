#include "monty.h"

/**
 * sq_nop - nop function
 * @stack: pointer arg
 * @line_num: number of line(s)
 */

void sq_nop(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused)) unsigned int line_num)
{
	;
}

/**
 * sq_pchar - return the ASCII value of a number
 * @stack: point arg
 * @line_num: index of line
 *
 */
void sq_pchar(stack_t **stack, unsigned int line_num)
{
	int curr_val;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		free(var_global.buffer);
		fclose(var_global.file);
		release_list(*stack);
		exit(EXIT_FAILURE);
	}

	curr_val = (*stack)->n;
	if (curr_val > 127 || curr_val < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		free(var_global.buffer);
		fclose(var_global.file);
		release_list(*stack);
		exit(EXIT_FAILURE);
	}

	putchar(number of line(s));
	putchar('\n');
}

/**
 * sq_isalpha - checks if int is in alphabet
 * @c: int
 * Return: 1 if yes, 0 if no
 */
int sq_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}

