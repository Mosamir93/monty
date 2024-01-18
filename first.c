#include "monty.h"
#include <stdio.h>
#include <string.h>

/**
 * args_init - initialises elements of the args structure
*/

void args_init(void)
{
    args = malloc(sizeof(arg_s));
    if (args == NULL)
        fail_malloc();

    args->line = NULL;
    args->stream = NULL;
    args->line_num = 0;
    args->tokens_num = 0;
    args->instruct = malloc(sizeof(instruction_t));
    args->s_len = 0;
    args->s = 1;
    args->head = NULL;
    if (args->instruct == NULL)
        fail_malloc();
}

/**
 * main - entry point
 * @argc: arguments count
 * @argv: arguments vector
 * Return: 0 on success
*/

int main(int argc, char **argv)
{
    size_t size = 0;
    ssize_t result;
    arg_s *args = NULL;
    
    args_init();
    check_args(argc);
    get_code(argv[1]);
    while ((result = getline(&args->line, &size, args->stream)) != -1)
    {
        tokenize();
        get_command();
        exec_command();
        tokens_free();
        (args->line_num)++;
    }
    close_file();
    args_free();

    return (0);
}

/**
 * check_args - checks the number of arguments (files)
 * @a: the number of arguments in CLI
*/

void check_args(int a)
{
    if (a != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    return;
}

/**
 * get_code - open the file to be interpreted
 * @file: the file to be opened
*/

void get_code(char *file)
{
    args->stream = fopen(file, "r");
    if (args->stream ==NULL)
    {
        get_code_fail(file);
    }
}

/**
 * get_code_fail - if the file openning fails it prints a message
 * to stderr and frees args and exit
 * @file: file that failed to open
*/

void get_code_fail(char *file)
{
    fprintf(stderr, "Error: Can't open file %s\n", file);
    args_free();
    exit(EXIT_FAILURE);
}
