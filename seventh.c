#include "monty.h"

void stack(stack_t **s, unsigned int line_num)
{
    (void) line_num;
    (void) s;
    args->s = 1;
}

void queue(stack_t **s, unsigned int line_num)
{
    (void) line_num;
    (void) s;
    args->s = 0;
}
