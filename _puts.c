#include "main.h"

/**
 * _putchar - putchar
 * @t: t
 *
 * Return: int 1;
*/
int _putchar(int t)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (t == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (t != BUF_FLUSH)
	{
		buf[i++] = t;
	}
	return (1);
}

/**
 * _puts - puts
 * @str: str
 *
 * Return: int
*/
int _puts(char *str)
{
	char *i = str;

	while (*str)
	{
		_putchar(*str++);
	}
	return (str - i);
}
