#include "main.h"

/**
 * main - func to start simple shell
 * @argc: argument coun
 * @argv: argument vector
 * Return: simple shell
 **/
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

    run_prompt();
	return (0);
}

/**
 * prompt - call prompt to start shell input
 *
 **/
void run_prompt(void)
{
    char *prompt;
    char **cmd_args;

	for (;;)
	{
        _stream_writer("$ ");
        prompt = read_prompt();
        cmd_args = tokenize(prompt);

        exec_cmd(cmd_args);
    }
    
    free(prompt);
    free(cmd_args);
}