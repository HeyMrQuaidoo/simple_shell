#include "main.h"

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
 *_strlen - function that returns
 * the length of a string.
 *
 *@s: char s
 *Return: Always success
 */
int _strlen(char *s)
{
	int n = 0;

	while (*s != '\0')
	{
		n++;
		s++;
	}
	return (n);
}

/**
 * _strcmp - function that compares two strings.
 * @s1: char 1 to compare
 * @s2: char 2 to compare
 * Return: 0 if char equal
 */
int _strcmp(char *s1, char *s2)
{
	int flag = 0;
	int s1_len, s2_len;
	s1_len = _strlen(s1);
	s2_len = _strlen(s2);

	if (s1_len != s2_len)
	{
		return (1);
	}

	while (*s2 != '\0' && *s1 != '\0')
	{
		if (*s1 != *s2){
			flag = 1;
			break;
		}

		s1++;
		s2++;
	}

	return (flag);
}

/**
 * _strcat - function that concatenates two strings.
 * @dest: dest string
 * @src: src string
 * Return: dest - concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
	{
		a++;
	}

	while (src[b] != '\0')
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (dest);
}