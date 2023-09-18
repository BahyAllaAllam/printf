#include "main.h"

/**
 * print_from_to -  print_from_to
 * @st: start
 * @stp: stop
 * @exc: except
 *
 * Return: number bytes printed
*/

int print_from_to(char *st, char *stp, char *exc)
{
	int total = 0;

	while (st <= stp)
	{
		if (st != exc)
			total += _putchar(*st);
		st++;
	}
	return (total);
}

/**
 * print_rev - print_rev
 * @list: list
 * @flags: flags
 *
 * Return: number bytes printed
*/

int print_rev(va_list list, flags_t *flags)
{
	int len, total = 0;
	char *s = va_arg(list, char *);
	(void)flags;

	if (s)
	{
		for (len = 0; *s; s++)
			len++;
		s--;
		for (; len > 0; len--, s--)
			total += _putchar(*s);
	}
	return (total);
}

/**
 * print_rot13 - rot13
 * @list: list
 * @flags: flags
 *
 * Return: number bytes printed
*/

int print_rot13(va_list list, flags_t *flags)
{
	int d = 0, n = 0, c = 0;
	char ar[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *p = va_arg(list, char *);
	(void)flags;

	while (p[n])
	{
		if ((p[n] >= 'A' && p[n] <= 'Z') || (p[n] >= 'a' && p[n] <= 'z'))
		{
			d = p[n] - 65;
			c += _putchar(ar[d]);
		}
		else
		{
			c += _putchar(p[n]);
		}
		n++;
	}
	return (c);
}
