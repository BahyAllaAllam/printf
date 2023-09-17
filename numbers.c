#include "main.h"

/**
 * convert - convert
 * @n: n
 * @b: b
 * @f: f
 * @params: params
 *
 * Return: string
*/

char *convert(long int n, int b, int f, params_t *params)
{
	static char *ar;
	static char buf[50];
	char s = 0;
	char *p;
	unsigned long num = n;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && n < 0)
	{
		num = -n;
		s = '-';
	}
	ar = f & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buf[49];
	*p = '\0';

	do	{
		*--p = ar[n % b];
		n /= b;
	} while (n != 0);

	if (sign)
		*--p = sign;
	return (p);
}

/**
 * print_unsigned - print_unsigned
 * @list: list
 * @params: params
 *
 * Return: int
*/
int print_unsigned(va_list list, parms_t *params)
{
	unsigned long a;

	if ((*params).l_modifier)
		a = (unsigned long)va_arg(list, unsigned long);
	else if ((*params).h_modifier)
		a = (unsigned short int)va_arg(list, unsigned short int);
	else
		a = (unsigned int)va_arg(list, unsigned int);
	(*params).unsign = 1;
	return (print_number(convert(a, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_address - print_address
 * @list: list
 * @params: params
 *
 * Return: int
*/
int print_address(va_list list, params_t *params)
{
	unsigned long int i = va_arg(list, unsigned long int);
	char *s;

	if (!i)
		return (_puts("(nill)"));
	s = convert(i, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--s = 'x';
	*--s = '0';
	return (print_number(s, params));
}
