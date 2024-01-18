#include "monty.h"

int _isdigit(char *s)
{
    int i;

    for (i = 0; s[i]; i++)
    {
        if(s[i] == '-' && i == 0 && s[i + 1])
            continue;
        if (s[i] > '9' || s[i] < '0')
            return (0);
    }
    return (1);
}

void tokens_free(void)
{
    int i;

    if (!(args->tokens))
        return;
    for (i = 0; args->tokens[i]; i++)
        free(args->tokens[i]);
    free(args->tokens);
    args->tokens = NULL;
}

void exec_command(void)
{
    stack_t *s =NULL;

    if (!(args->tokens_num))
        return;
    args->instruct->f(&s, args->line_num);
}

void push(stack_t **s, unsigned int line_num)
{
    stack_t *t;

    if (!(_isdigit(args->tokens[1])) || args->tokens_num <= 1)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_num);
        all_free();
        exit(EXIT_FAILURE);
    }
    *s = malloc(sizeof(stack_t));
    if (!(*s))
    {
        close_file();
        tokens_free();
        fail_malloc();
    }
    (*s)->next = (*s)->prev = NULL;
    (*s)->n = atoi(args->tokens[1]);
    if (!(args->head))
        args->head = *s;
    else
    {
        if (!(args->s))
        {
            t = args->head;
            while (t->next != NULL)
                t = t->next;
            t->next = *s;
            (*s)->prev = t;
        }
        else
        {
            (*s)->next = args->head;
            args->head->prev = *s;
            args->head = *s;
        }
    }
    (args->s_len)++;
}

void pall(stack_t **s, unsigned int line_num)
{
    stack_t *temp;
    int i;

    (void) s;
    (void) line_num;

    if (args->head == NULL)
        return;
    temp = args->head;
    for (i = 0; temp; i++)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}
