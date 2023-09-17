#include "main.h"

/**
* _isdigit - checks if character is digit
*
* @x: the character to check
*
* Return: 1 if digit
*	0 otherwise
*/

int _isdigit(int x)
{
	return (x >= '0' && x <= '9');
}

/**
* _strlen - returns the length of s
*
* @s: string to be checked
*
* Return: the length of s
*/

int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
* print_number - prints a number with options
*
*@s: the base number as a string
*@flags: the parameter struct
*
* Return: chars printed
*/
int print_number(char *s, flags_t *flags)
{
	unsigned int i = _strlen(s);
	int neg = (!(*flags).unsign && *s == '-');

	if (!(*flags).precision && *s == '0' && !s[1])
		s = "";
	if (neg)
	{
		s++;
		i--;
	}
	if ((*flags).precision != UINT_MAX)
	{
		while (i++ < (*flags).precision)
			*--s = '0';
	}
	if (neg)
		*--s = '-';
	if (!(*flags).minus_flag)
		return (print_number_right_shift(s, flags));
	else
		return (print_number_left_shift(s, flags));
}

/**
* print_number_right_shift - prints a number with options
*
*@s: the base number as a string
*@flags: the parameter struct
*
*Return: chars printed
*/
int print_number_right_shift(char *s, flags_t *flags)
{
	unsigned int n = 0, neg, neg2, i  = _strlen(s);
	char pad_char = ' ';

	if ((*flags).zero_flag && !(*flags).minus_flag)
		pad_char = '0';
	neg = neg2 = (!(*flags).unsign && *s == '-');
	if (neg && i < (*flags).width && pad_char == '0' && !(*flags).minus_flag)
		s++;
	else
		neg = 0;
	if (((*flags).plus_flag && !neg2) ||
	(!(*flags).plus_flag && (*flags).space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar ('-');

	if ((*flags).plus_flag && !neg2 && pad_char == '0' && !(*flags).unsign)
		n += _putchar ('+');
	else if (!(*flags).plus_flag && (*flags).space_flag && !neg2 &&
	!(*flags).unsign && (*flags).zero_flag)
		n += _putchar(' ');
	while (i++ < (*flags).width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if ((*flags).plus_flag && !neg2 && pad_char == ' ' && !(*flags).unsign)
		n += _putchar('+');
	else if (!(*flags).plus_flag && (*flags).space_flag && !neg2 &&
	!(*flags).unsign && !(*flags).zero_flag)
		n += _putchar(' ');
	n += _puts(s);
	return (n);
}

/**
*print_number_left_shift - prints a number with options
*
*@s: the base number as a string
*@flags: the parameter struct
*
*Return: chars printed
*/

int print_number_left_shift(char *s, flags_t *flags)
{
	unsigned int n = 0, neg, neg2, i = _strlen(s);
	char pad_char = ' ';

	if ((*flags).zero_flag & !(*flags).minus_flag)
		pad_char = '0';
	neg = neg2 = (!(*flags).unsign && *s == '-');
	if (neg && i < (*flags).width && pad_char == '0' && !(*flags).minus_flag)
		s++;
	else
		neg = 0;

	neg = 0;
	if ((*flags).plus_flag && !neg2 && !(*flags).unsign)
		n += _putchar ('+'), i++;
	else if ((*flags).space_flag && !neg2 && !(*flags).unsign)
		n += _putchar(' '), i++;
	n += _puts(s);
	while (i++ < (*flags).width)
		n += _putchar(pad_char);
	return (n);
}
