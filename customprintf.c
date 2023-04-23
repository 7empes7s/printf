#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <limits.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    char buffer[1024] = {0};
    size_t i;
    int j = 0;
    format_t formats[] = {
        {'c', print_char},
        {'s', print_str},
        {'%', print_percent},
        {'d', print_int},
        {'i', print_int},
        {'u', print_unsigned_int},
        {'b', print_binary},
        {'o', print_octal},
        {'x', print_hex},
        {'X', print_hex},
        {'p', print_address},
        {'r', print_reversed},
        {'R', print_rot13},
        {0, NULL}};

    va_start(args, format);
    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            int k = 0;

            while (formats[k].type != 0)
            {
                if (formats[k].type == format[i])
                {
                    formats[k].func(args, buffer, &j);
                    break;
                }
                k++;
            }
            if (formats[k].type == 0)
            {
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
