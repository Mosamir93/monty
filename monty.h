#ifndef MONTY_H
#define MONTY_H

#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct arguments - structure to be used globally
 * throughout the whole interpreter
 * @line: line of text read from the file
 * @stream: file pointer to the opened file
 * @instruct: instruction obtained from each line
 * @tokens_num: the number of tokens obtained
 * @line_num: the line number thats instruction and token obtained from
 * @tokens: ana array of tokens
 * @head: pointer to the stack to store the head of it
 * @s: int to store 1 if FIFO format 0 if LIFO
 * @s_len: length of the stack
 *
 * Description: structure to be used globally to store info about the
 * instructions, tokens, file, stack and it's format
 */
typedef struct arguments
{
	char *line;
	FILE *stream;
	instruction_t *instruct;
	int tokens_num;
	unsigned int line_num;
	char **tokens;
	stack_t *head;
	int s;
	int s_len;
} arg_s;

extern arg_s *args;

void args_init(void);
void check_args(int a);
void get_code(char *file);
void get_code_fail(char *file);
void fail_malloc(void);
void close_file(void);
void tokenize(void);
void get_command(void);
void command_invalid(void);
int _isdigit(char *s);
void tokens_free(void);
void exec_command(void);
void push(stack_t **s, unsigned int line_num);
void pall(stack_t **s, unsigned int line_num);
void args_free(void);
void all_free(void);
void pint(stack_t **s, unsigned int line_num);
void pop(stack_t **s, unsigned int line_num);
void swap(stack_t **s, unsigned int line_num);
void add(stack_t **s, unsigned int line_num);
void nop(stack_t **s, unsigned int line_num);
void sub(stack_t **s, unsigned int line_num);
void _div(stack_t **s, unsigned int line_num);
void mul(stack_t **s, unsigned int line_num);
void mod(stack_t **s, unsigned int line_num);
void pchar(stack_t **s, unsigned int line_num);
void pstr(stack_t **s, unsigned int line_num);
void rotl(stack_t **s, unsigned int line_num);
void rotr(stack_t **s, unsigned int line_num);
void stack(stack_t **s, unsigned int line_num);
void queue(stack_t **s, unsigned int line_num);

#endif
