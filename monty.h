#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/*--- Struct Definitions ---*/
extern int inject;

/**
 * struct stack_s - linked list
 * @n: integer arg
 * @prev: previous arg
 * @next: next arg
 * Description: doubly linked list node structure
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct command_s - operation
 * @opcode: the operator
 * @f: function to operator
 * Description: operation and its function
 */
typedef struct command_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_num);
} command_t;

/**
 * struct super_variable - opcoode and its function
 * @file: the opcode
 * @inject: function to handle the opcode
 * @buffer: pointer to
 * Description: operation and its function
 */
typedef struct super_variable
{
	FILE *file;
	int inject;
	char *buffer;
} super_var;

extern super_var var_global;

void open_file(char *filename, stack_t **stack);
char *scan_line(char *line, stack_t **stack, unsigned int line_num);
typedef void (*instruct_func)(stack_t **stack, unsigned int line_num);
instruct_func get_op_func(char *str);

void sq__pall(stack_t **stack, unsigned int line_num);
void sq_push(stack_t **stack, unsigned int line_num);
void sq_pint(stack_t **stack, unsigned int line_num);
void sq_pop(stack_t **stack, unsigned int line_num);
void sq_swap(stack_t **stack, unsigned int line_num);
void sq_nop(stack_t **stack, unsigned int line_num);
void sq_rotl(stack_t **stack, unsigned int line_num);
void sq_rotr(stack_t **stack, unsigned int line_num);
void sq_pchar(stack_t **stack, unsigned int line_num);
void sq_pstr(stack_t **stack, unsigned int line_num);
void sq_sub(stack_t **stack, unsigned int line_num);
void sq_add(stack_t **stack, unsigned int line_num);
void sq_mul(stack_t **stack, unsigned int line_num);
void sq_div(stack_t **stack, unsigned int line_num);
void sq_mod(stack_t **stack, unsigned int line_num);
void release_list(stack_t *head);
void doub_rel(stack_t **stack);
void doub_release(stack_t **stack);
int sq_isalpha(int c);
#endif
