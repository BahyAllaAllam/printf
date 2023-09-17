#include "main.h"

/**
 * get_percision - get percision
 * @ptr: ptr
 * @params: params
 * @list: list
 *
 * Return: new pointer
*/

char *get_precision(char *ptr, params_t *params, va_list list)
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
