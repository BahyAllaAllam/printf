#include "main.h"

/**
* print_hex - prints unsigned hex numbers in lowercase
* @list: the argument pointer
* @flags: the parameters struct
*
* Return: bytes printed
*/

int print_hex(va_list list, flags_t *flags)
{
	unsigned long l;
	int c = 0;
	char *str;

	if ((*flags).l_modifier)
		l = (unsigned long)va_arg(list, unsigned long);
	else if ((*flags).h_modifier)
		l = (unsigned short int)va_arg(list, unsigned int);
	else
		l = (unsigned int)va_arg(list, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, flags);
	if ((*flags).hashtag_flag && 1)
	{
		*--str = 'x';
		*--str = '0';
	}
	(*flags).unsign = 1;
	return (c += print_number(str, flags));
}

/**
*print_HEX - prints unsigned hex numbers in uppercase
*
*@list: the argument pointer
*@flags: the parameters struct
*
*Return: bytes printed
*/

int print_HEX(va_list list, flags_t *flags)
{
	unsigned long l;
	int c = 0;
	char *str;

	if ((*flags).l_modifier)
		l = (unsigned long)va_arg(list, unsigned long);
	else if ((*flags).h_modifier)
		l = (unsigned short int)va_arg(list, unsigned int);
	else
		l = (unsigned int)va_arg(list, unsigned int);
	str = convert(l, 16, CONVERT_UNSIGNED, flags);
	if ((*flags).hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	(*flags).unsign = 1;
	return (c += print_number(str, flags));
}

/**
*print_binary - prints unsigned binary number
*
*@list: the argument pointer
*@flags: the parameters struct
*
*Return: bytes printed
*/
int print_binary(va_list list, flags_t *flags)
{
	unsigned int n = va_arg(list, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, flags);
	int c = 0;

	if ((*flags).hashtag_flag && n)
		*--str = '0';
	(*flags).unsign = 1;
	return (c += print_number(str, flags));
}

/**
* print_octal - prints unsigned octal numbers
*
* @list: the argument pointer
* @flags: the parameters struct.
*
*Return: bytes printed
*/

int print_octal(va_list list, flags_t *flags)
{
	unsigned long l;
	char *str;
	int c = 0;

	if ((*flags).l_modifier)
		l = (unsigned long)va_arg(list, unsigned long);
	else if ((*flags).h_modifier)
		l = (unsigned short int)va_arg(list, unsigned int);
	else
		l = (unsigned int)va_arg(list, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, flags);

	if ((*flags).hashtag_flag && 1)
		*--str = '0';
	(*flags).unsign = 1;
	return (c += print_number(str, flags));
}
