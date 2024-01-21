#include "monty.h"

/**
 * args_free - free the args structure
 */

void args_free(void)
{
	stack_t *temp;

	if (!args)
		return;
	if (args->instruct != NULL)
	{
		free(args->instruct);
		args->instruct = NULL;
	}
	if (args->head)
	{
		while (args->head)
		{
			temp = args->head;
			args->head = args->head->next;
			free(temp);
		}
	}
	if (args->line != NULL)
	{
		free(args->line);
		args->line = NULL;
	}
	free(args);
}

/**
 * all_free - frees args struct, closes the file and frees tokens
 */

void all_free(void)
{
	close_file();
	tokens_free();
	args_free();
}

/**
 * pint - prints the value at the top of the stack
 * @s: pointer to pointer to the stack
 * @line_num: the lines's number in the file at which the instruction exists
 */
void pint(stack_t **s, unsigned int line_num)
{
	if (!(args->head))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		all_free();
		exit(EXIT_FAILURE);
	}

	(void) s;

	printf("%d\n", args->head->n);
}

/**
 * pop - removes the top element of the stack
 * @s: pointer to pointer to the stack
 * @line_num: the lines's number in the file at which the instruction exists
 */

void pop(stack_t **s, unsigned int line_num)
{
	stack_t *temp;

	if (!(args->head))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		all_free();
		exit(EXIT_FAILURE);
	}

	(void) s;

	temp = args->head;
	args->head = temp->next;
	free(temp);
	(args->s_len)--;
}

/**
 * swap - swaps the top 2 elements of the stack
 * @s: pointer to pointer to the stack
 * @line_num: the lines's number in the file at which the instruction exists
 */

void swap(stack_t **s, unsigned int line_num)
{
	stack_t *t1, *t2;

	if (args->s_len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		all_free();
		exit(EXIT_FAILURE);
	}
	(void) s;
	t1 = args->head;
	t2 = t1->next;
	t1->next = t2->next;
	if (t1->next != NULL)
		t1->next->prev = t1;
	args->head = t2;
	t1->prev = t2;
	t2->next = t1;
	t2->prev = NULL;
}
