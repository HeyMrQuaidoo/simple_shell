#include "main.h"

/**
 * exec_cmd - Runs shell commands
 * @args: command line arguments
 *
 * Return: current pid of shell
 **/
int exec_cmd(char **args)
{
	pid_t child_pid;
	int status;

	if (args[0] == NULL)
	{
		return (1);
	}

	run_exit_checker(args[0]);

	if (run_check_cmd_exists(args) == 0)
	{
		child_pid = fork();

		if (child_pid < 0)
			perror("Error creating child fork");

		if (child_pid == 0)
		{
			runner(args);
		}
		else
		{
			wait(&status);
		}
	}

	return (status);
}

/**
 * run_exit_checker - Checks if shell should exit
 * @prompt_text: command line arguments
 *
 * Return: exits shell
 **/
void run_exit_checker(char *prompt_text)
{
	if (_strcmp(prompt_text, "exit") == 0)
		exit(0);
}

/**
 * run_check_cmd_exists - Check if command exists in path
 * @cmd: command line arguments
 *
 * Return: Returns 1 if command not found else 0
 **/
int run_check_cmd_exists(char **cmd)
{
	if ((access(cmd[0], F_OK) != 0))
	{
		perror("command not found");
		return (1);
	}

	return (0);
}


/**
 * runner - Runs shell commands
 * @cmd: command line arguments
 *
 * Return: nothing
 **/
void runner(char **cmd)
{
	char *param = (*(cmd + 1));
	char *argv[4];

	argv[0] = cmd[0];
	argv[1] = param;
	argv[2] = NULL;
	argv[3] = NULL;

	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error executing command");
	}
}
