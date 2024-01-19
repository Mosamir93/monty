#include "monty.h"
#include <string.h>
#include <stdio.h>

/**
 * close_file - closes the opened file
 */

void close_file(void)
{
	if (!(args->stream))
		return;
	fclose(args->stream);
	args->stream = NULL;
}

/**
 * tokenize - tokenizes lines obtained from the file
 */

void tokenize(void)
{
	char *cpy, *delim = " \n", *token = NULL;
	int i;

	cpy = strdup(args->line);
	if (cpy == NULL)
		fail_malloc();
	token = strtok(cpy, delim);
	for (args->tokens_num = 0; token; args->tokens_num++)
		token = strtok(NULL, delim);
	args->tokens = malloc((args->tokens_num + 1) * sizeof(char *));
	if (args->tokens == NULL)
		fail_malloc();
	free(cpy);
	cpy = strdup(args->line);
	if (cpy == NULL)
		fail_malloc();
	token = strtok(cpy, delim);
	for (i = 0; token; i++)
	{
		args->tokens[i] = strdup(token);
		if (args->tokens[i] == NULL)
			fail_malloc();
		token = strtok(NULL, delim);
	}
	args->tokens[i] = NULL;
	free(cpy);
}

/**
 * get_command - get the relevant command (instruction)
 * from the instruction_t structure
 */

void get_command(void)
{
	int i;
	instruction_t command[] = {
		{"pop", &pop}, {"push", &push},
		{"add", &add}, {"swap", &swap},
		{"nop", &nop}, {"pint", &pint},
		{"mul", &mul}, {"sub", &sub},
		{"pall", &pall}, {"div", &_div},
		{"rotr", &rotr}, {"stack", &stack},
		{"queue", &queue}, {"rotl", &rotl},
		{"pchar", &pchar}, {"mod", &mod},
		{"pstr", &pstr},
		{NULL, NULL}
	};
	if (!(args->tokens_num))
		return;
	if (args->tokens[0][0] == '#')
	{
		args->instruct->f = nop;
		args->instruct->opcode = "nop";
		return;
	}
	for (i = 0; command[i].opcode; i++)
	{
		if (strcmp(command[i].opcode, args->tokens[0]) == 0)
		{
			args->instruct->f = command[i].f;
			args->instruct->opcode = command[i].opcode;
			return;
		}
	}
	command_invalid();
}

/**
 * command_invalid - prints a message to stderr if the command is invalid
 */

void command_invalid(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
			args->line_num, args->tokens[0]);
	close_file();
	tokens_free();
	args_free();
	exit(EXIT_FAILURE);
}

/**
 * fail_malloc - prints a message to stderr if malloc failed and frees
 * args and exit
 */

void fail_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	args_free();
	exit(EXIT_FAILURE);
}
