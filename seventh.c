#include "monty.h"

/**
 * stack - sets the format of data in a stack(LIFO)
 * @s: pointer to pointer to the stack
 * @line_num: the lines's number in the file at which the instruction exists
 */

void stack(stack_t **s, unsigned int line_num)
{
	(void) line_num;
	(void) s;
	args->s = 1;
}

/**
 * queue - sets the format of data in a stack(FIFO)
 * @s: pointer to pointer to the stack
 * @line_num: the lines's number in the file at which the instruction exists
 */

void queue(stack_t **s, unsigned int line_num)
{
	(void) line_num;
	(void) s;
	args->s = 0;
}
