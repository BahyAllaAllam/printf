#include "main.h"

/**
 * convert - convert
 * @n: n
 * @b: b
 * @f: f
 * @flags: params
 *
 * Return: string
*/

char *convert(long int n, int b, int f, flags_t *flags)
{
	static char *ar;
	static char buf[50];
	char s = 0;
	char *p;
	unsigned long num = n;
	(void)flags;

	if (!(f & CONVERT_UNSIGNED) && n < 0)
	{
		num = -n;
		s = '-';
	}
	ar = f & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buf[49];
	*p = '\0';

	do	{
		*--p = ar[num % b];
		num /= b;
	} while (num != 0);

	if (s)
		*--p = s;
	return (p);
}

/**
 * print_unsigned - print_unsigned
 * @list: list
 * @flags: flags
 *
 * Return: int
*/
int print_unsigned(va_list list, flags_t *flags)
{
	unsigned long a;

	if ((*flags).l_modifier)
		a = (unsigned long)va_arg(list, unsigned long);
	else if ((*flags).h_modifier)
		a = (unsigned short int)va_arg(list, unsigned int);
	else
		a = (unsigned int)va_arg(list, unsigned int);
	(*flags).unsign = 1;
	return (print_number(convert(a, 10, CONVERT_UNSIGNED, flags), flags));
}

/**
 * print_address - print_address
 * @list: list
 * @flags: flags
 *
 * Return: int
*/
int print_address(va_list list, flags_t *flags)
{
	unsigned long int i = va_arg(list, unsigned long int);
	char *s;

	if (!i)
		return (_puts("(nill)"));
	s = convert(i, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, flags);
	*--s = 'x';
	*--s = '0';
	return (print_number(s, flags));
}
