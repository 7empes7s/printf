#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 * @c: character to write
 * Return: 1 on success, -1 on failure
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - produces output according to a format
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++; /* skip the conversion specifier */
			switch (format[i])
			{
				case 'c':
					_putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					count += write(1, va_arg(args, char *), strlen(va_arg(args, char *)));
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}

	va_end(args);

	return (count);
}
