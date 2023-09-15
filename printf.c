#include <unistd.h>
#include <stdarg.h>
#include <string.h>

/**
 * format_checker - takes a format specifier and prints its corresponding variable
 *
 * @i: i
 * @format: format specifier
 * @ap: va_list
 * @nbytes: number of chars printed
 *
 * Return: 1 if valid format specifier
 * 	0 otherwise
 */
int format_checker(int i, const char *format, va_list ap, int *nbytes)
{
	int z;
	char *x, y = '%';

	switch (format[i++])
	{
		case 'c':
			z = va_arg(ap, int);
			write(1, &z, 1);
			*nbytes += 1;
			break;
		case 's':
			x = va_arg(ap, char *);
			write(1, x, strlen(x));
			*nbytes += strlen(x);
			break;
		case '%':
			write(1, &y, 1);
			*nbytes += 1;
			break;
		default:
			return (0);
	}
	return (1);
}


/**
 * _printf - printf function
 *
 * @format: string to be formated
 *
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int nbytes = 0, i = 0, x;

	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			x = format_checker(i, format, ap, &nbytes);
			if (x == 0)
				continue;
			i++;
		}
		else
		{
			write(1, format + i, 1);
				nbytes++;
				i++;
		}
	}
	return (nbytes);
}
