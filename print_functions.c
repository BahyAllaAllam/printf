#include "main.h"

/**
* print_char - prints character
*
* @list: argument pointer
* @flags: the parameters struct.
*
*Return: number chars printed.
*/

int print_char(va_list list, flags_t *flags)
{
	char pad_char = ' ';
	unsigned int pad = 1, total = 0, ch = va_arg(list, int);

	if ((*flags).minus_flag)
		total += _putchar(ch);
	while (pad++ < (*flags).width)
		total += _putchar(pad_char);
	if (!(*flags).minus_flag)
		total += _putchar(ch);
	return (total);
}

/**
*print_int - prints integer
*
*@list: argument pointer
*@flags: the parameters struct
*
*Return: number chars printed
*/
int print_int(va_list list, flags_t *flags)
{
	long i;

	if ((*flags).l_modifier)
		i = va_arg(list, long);
	else if ((*flags).h_modifier)
		i = (short int)va_arg(list, int);
	else
		i = (int)va_arg(list, int);
	return (print_number(convert(i, 10, 0, flags), flags));
}

/**
* print_string - prints string
*
* @list: argument pointer
* @flags: the parameters struct
*
* Return: number chars printed.
*/
int print_string(va_list list, flags_t *flags)
{
	char *s = va_arg(list, char *), pad_char = ' ';
	unsigned int pad = 0, total = 0, i = 0, j;

	(void)flags;
	switch ((int)(!s))
		case 1:
			s = NULL_STRING;
	j = pad = _strlen(s);
	if ((*flags).precision < pad)
		j = pad = (*flags).precision;
	if ((*flags).minus_flag)
	{
		if ((*flags).precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				total += _putchar(*s++);
		else
			total += _puts(s);
	}

	while (j++ < (*flags).width)
		total += _putchar(pad_char);
	if (!(*flags).minus_flag)
	{
		if ((*flags).precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				total += _putchar(*s++);
		else
			total += _puts(s);
	}
	return (total);
}

/**
* print_percent - prints string.
*
* @list: argument pointer
* @flags: the parameters struct
*
*Return: number chars printed.
*/
int print_percent(va_list list, flags_t *flags)
{
	(void)list;
	(void)flags;
	return (_putchar('%'));
}

/**
*print_S - custom format specifier
*
* @list: argument pointer
* @flags: the parameters struct
*
*Return: number chars printed.
*/

int print_S(va_list list, flags_t *flags)
{
	char *s = va_arg(list, char *);
	char *h;
	int total = 0;

	if ((int)(!s))
		return (_puts(NULL_STRING));
	for (; *s; s++)
	{
		if ((*s > 0 && *s < 32) || *s >= 127)
		{
			total += _putchar('\\');
			total += _putchar('x');
			h = convert(*s, 16, 0, flags);
			if (!h[1])
				total += _putchar('0');
			total += _puts(h);
		}
		else
		{
			total += _putchar(*s);
		}
	}
	return (total);
}
