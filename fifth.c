#include "monty.h"

/**
 * add - adds the top two elements of a stack
 * @s: pointer to pointer to the stack
 * @line_num: the lines's number in the file at which the instruction exists
 */

void add(stack_t **s, unsigned int line_num)
{
	stack_t *t1, *t2;

	if (args->s_len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		all_free();
		exit(EXIT_FAILURE);
	}

	(void) s;
	t1 = args->head;
	t2 = args->head->next;
	t2->n = t2->n + t1->n;
	args->head = t2;
	free(t1);
	args->s_len--;
}

/**
 * nop - does nothing
 * @s: pointer to pointer to the stack
 * @line_num: the lines's number in the file at which the instruction exists
 */

void nop(stack_t **s, unsigned int line_num)
{
	(void) s;
	(void) line_num;
}

/**
 * sub - subtracts the top element from the second top in the stack
 * @s: pointer to pointer to the stack
 * @line_num: the lines's number in the file at which the instruction exists
 */

void sub(stack_t **s, unsigned int line_num)
{
	stack_t *t1, *t2;

	if (args->s_len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		all_free();
		exit(EXIT_FAILURE);
	}

	(void) s;
	t1 = args->head;
	t2 = args->head->next;
	t2->n = t2->n - t1->n;
	args->head = t2;
	free(t1);
	(args->s_len)--;
}

/**
 * _div - divides second top in the stack by the the top element in the stack
 * @s: pointer to pointer to the stack
 * @line_num: the lines's number in the file at which the instruction exists
 */

void _div(stack_t **s, unsigned int line_num)
{
	stack_t *t1, *t2;

	if (args->s_len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		all_free();
		exit(EXIT_FAILURE);
	}
	if (args->head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		all_free();
		exit(EXIT_FAILURE);
	}

	(void) s;
	t1 = args->head;
	t2 = args->head->next;
	t2->n = t2->n / t1->n;
	args->head = t2;
	free(t1);
	(args->s_len)--;
}

/**
 * mul - multiplies second top in the stack by the the top element in the stack
 * @s: pointer to pointer to the stack
 * @line_num: the lines's number in the file at which the instruction exists
 */

void mul(stack_t **s, unsigned int line_num)
{
	stack_t *t1, *t2;

	if (args->s_len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		all_free();
		exit(EXIT_FAILURE);
	}

	(void) s;
	t1 = args->head;
	t2 = args->head->next;
	t2->n = t2->n * t1->n;
	args->head = t2;
	free(t1);
	(args->s_len)--;
}
