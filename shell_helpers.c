#include "main.h"

/**
 * find_trailing_slash - identifies if first char
 * is a slash.
 * @cmd: first string
 * Return: 1 if yes 0 if no.
 */
int find_trailing_slash(char *cmd)
{
	int cont = 0;

	while (cmd[cont])
	{
		if (cmd[0] == '/')
		{
			printf("%c\n", cmd[0]);
			return (1);
		}

		cont++;
	}
	return (0);
}


/**
 * run_shell - keep shell alive
 * @sig: keeps shell alive
 **/
void run_shell(int sig)
{
	(void) sig;
	write(1, "\n$ ", 3);
}

/**
 *  _putchar - Takes in char c and outputs to stdout
 *  @c: Character c to output to stdout
 *
 *  Return: Always 0 (Success)
 *
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _stream_writer - write a line or string to the output
 * @str: char str to output to stdout
 *
 * Return: Always 0 (Success)
 */
void _stream_writer(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}


/**
 * _strcmp - function that compares two strings.
 * @s1: char 1 to compare
 * @s2: char 2 to compare
 * Return: 0 if char equal
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	for (; (*s2 != '\0' && *s1 != '\0') && *s1 == *s2; s1++)
	{
		if (i == 1)
			break;
		i++;
		s2++;
	}

	return (*s1 - *s2);
}

