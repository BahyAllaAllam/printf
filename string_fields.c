#include "main.h"

/**
 * get_precision - get percision
 * @ptr: ptr
 * @flags: flags
 * @list: list
 *
 * Return: new pointer
*/

char *get_precision(char *ptr, flags_t *flags, va_list list)
{
	int i = 0;

	if (*ptr != '.')
		return (ptr);
	ptr++;
	if (*ptr == '*')
	{
		i = va_arg(list, int);
		ptr++;
	}
	else
	{
		while (_isdigit(*ptr))
		{
			i = i * 10 + (*ptr++ - '0');
		}
	}
	(*params).precision = i;
	return (ptr);
}
