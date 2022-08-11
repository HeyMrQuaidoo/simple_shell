#include "main.h"

/**
 * main - func to start simple shell
 * @ac: No use
 * @av: No use
 * Return: loop.
 **/
int main(int ac, char **av)
{
	(void)av;
	(void)ac;

	signal(SIGINT, run_shell);
	prompt();
	return (0);
}
