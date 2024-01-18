#include "monty.h"

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

void nop(stack_t **s, unsigned int line_num)
{
    (void) s;
    (void) line_num;
}

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
