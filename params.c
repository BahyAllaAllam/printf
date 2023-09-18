#include "main.h"

/**
 * init_params - init_params
 * @flags: flags
 * @list: list
 *
 * Return: void
*/

void init_params(flags_t *flags, va_list list)
{
	(*flags).unsign = 0;
	(*flags).plus_flag = 0;
	(*flags).space_flag = 0;
	(*flags).hashtag_flag = 0;
	(*flags).zero_flag = 0;
	(*flags).minus_flag = 0;
	(*flags).width = 0;
	(*flags).precision = UINT_MAX;
	(*flags).h_modifier = 0;
	(*flags).l_modifier = 0;
	(void)list;
}
