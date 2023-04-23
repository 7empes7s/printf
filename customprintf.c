#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	char buffer[1024] = {0};
	size_t i, j = 0;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					buffer[j++] = (char)va_arg(args, int);
					break;
				case 's':
				{
					char *str = va_arg(args, char *);
					size_t k;

					for (k = 0; str[k] != '\0'; k++)
						buffer[j++] = str[k];
					break;
				}
				case '%':
					buffer[j++] = '%';
					break;
				default:
					buffer[j++] = format[i - 1];
					buffer[j++] = format[i];
			}
		}
		else
			buffer[j++] = format[i];
	}
	va_end(args);

	return write(1, buffer, j);
}
