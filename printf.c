#include "main.h"

/**
 * _printf - printf function
 *
 * @format: string to be formated
 *
 * Return: number of chars printed
*/
int _printf(const char *format, ...)
{
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	int total = 0;
	char *ptr, *sta;
	flags_t flags = PARAMS_INIT;

	va_list list;

	va_start(list, format);

	for (ptr = (char *)format; *ptr; ptr++)
	{
		init_params(&flags, list);
		if (*ptr != '%')
		{
			total += _putchar(*ptr);
			continue;
		}
		sta = ptr;
		ptr++;
		while (get_flag(ptr, &flags))
			ptr++;
		ptr = get_width(ptr, &flags, list);
		ptr = get_precision(ptr, &flags, list);
		if (get_modifier(ptr, &flags))
			ptr++;
		if (!get_specifier(ptr))
		{
			total += print_from_to(sta, ptr,
					flags.l_modifier || flags.h_modifier ? ptr - 1 : 0);
		}
		else
			total += get_print_func(ptr, list, &flags);
	}
	_putchar(BUF_FLUSH);
	va_end(list);
	return (total);
}
