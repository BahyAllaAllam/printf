#include "main.h"

/**
 * get_specifier - return format
 *
 * @ptr: format string
 *
 * Return: formated function
*/

int (*get_specifier(char *ptr))(va_list list, flags_t *flags)
{
	spec_t speci[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_int},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (speci[i].speci)
	{
		if (*ptr == speci[i].speci[0])
			return (speci[i].f);
		i++;
	}
	return (NULL);
}

/**
* get_print_func - finds the format func
*
* @str: the format string
* @list: argument pointer
* @flags: the parameters struct
*
* Return: the number of bytes printed
*/

int get_print_func(char *str, va_list list, flags_t *flags)
{
	int (*f)(va_list, flags_t *) = get_specifier(str);

	if (f)
		return (f(list, flags));
	return (0);
}

/**
 * get_flag - change flag
 *
 * @str: format string
 * @flags: parameters
 *
 * Return: 1 if flag is valid
 *	0 otherwise
 */

int get_flag(char *str, flags_t *flags)
{
	int i = 0;

	switch (*str)
	{
		case '+':
			i = (*flags).plus_flag = 1;
			break;
		case ' ':
			i = (*flags).space_flag = 1;
			break;
		case '#':
			i = (*flags).hashtag_flag = 1;
			break;
		case '-':
			i = (*flags).minus_flag = 1;
			break;
		case '0':
			i = (*flags).zero_flag = 1;
			break;
	}
	return (i);
}
/**
* get_modifier - finds the modifier func.
*
* @str: the format string
* @flags: the parameters struct.
*
* Return: 1 if modifier was valid
*	0 otherwise
*/

int get_modifier(char *str, flags_t *flags)
{
	int i = 0;

	switch (*str)
	{
		case 'h':
			i = (*flags).h_modifier = 1;
			break;
		case 'l':
			i = (*flags).l_modifier = 1;
			break;
	}
	return (i);
}
/**
* get_width - gets the width from the format string
*
* @str: format string
* @flags: parameters
* @list: argument pointer
*
* Return: pointer
*/

char *get_width(char *str, flags_t *flags, va_list list)
{
	int i = 0;

	if (*str == '*')
	{
		i = va_arg(list, int);
		str++;
	}
	else
	{
		while (_isdigit(*str))
			i = i * 10 + (*str++ - '0');
	}
	(*flags).width = i;
	return (str);
}
