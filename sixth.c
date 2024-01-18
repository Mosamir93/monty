#include "monty.h"

void mod(stack_t **s, unsigned int line_num)
{
           stack_t *t1, *t2;

    if (args->s_len < 2)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
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
    t2->n = t2->n % t1->n;
    args->head = t2;
    free(t1);
    (args->s_len)--;
}

void pchar(stack_t **s, unsigned int line_num)
{
    stack_t *t;

    if (!(args->head))
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
        all_free();
        exit (EXIT_FAILURE);
    }

    (void) s;
    t = args->head;
    if (t->n > 127 || t->n < 0)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
        all_free();
        exit(EXIT_FAILURE);
    }
    printf("%c\n", t->n);
}

void pstr(stack_t **s, unsigned int line_num)
{
    stack_t *t;

    t = args->head;
    while (t)
    {
        if (t->n > 127 || t->n <= 0)
            break;
        printf("%c", t->n);
        t = t->next;
    }

    (void) line_num;
    (void) s;
    printf("\n");
}

void rotl(stack_t **s, unsigned int line_num)
{
    stack_t *t1, *t2;

    if (args->s_len < 2)
        return;
    (void) line_num;
    (void) s;
    t1 = args->head;
    t2 = args->head->next;
    args->head = t2;
    while (t2 && t1->next)
    {
        if (!(t2->next))
        {
            t2->next = t1;
            t1->next = NULL;
            t1->prev = t2;
        }
        t2 = t2->next;
    }
}

void rotr(stack_t **s, unsigned int line_num)
{
    stack_t *t1, *t2;

    if (args->s_len < 2)
        return;
    (void) line_num;
    (void) s;
    t1 = args->head;
    while (t1)
    {
        if (!(t1->next))
        {
            t2 = t1;
            break;
        }
        t1 = t1->next;
    }
    t2->prev->next = NULL;
    t2->next = args->head;
    args->head = t2;
    t2->prev = NULL;
}
