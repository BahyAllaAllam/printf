#include <unistd.h>
#include <stdarg.h>
#include <string.h>

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
	int nbytes = 0, i = 0;
	char *x;
	char y;

	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch(format[i])
			{
				case 'c':

					write(1, va_arg(ap, int),1);
					nbytes++;
					break;
				case 's':
					x = va_arg(ap, char *);
					write(1, x, strlen(x));
					nbytes += strlen(x);
					break;
				case '%':
					y = '%';
					write(1, &y, 1);
					nbytes++;
				default:
					continue;
					

			}
		}
		else
		{
			write(1, format + i, 1);
				nbytes++;
		}
	}
	return (nbytes);

}
