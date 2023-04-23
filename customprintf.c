#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <limits.h>

int _putchar(char c)
{
    return write(1, &c, 1);
}

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
        {'b', print_binary},
        {'u', print_unsigned},
        {'o', print_octal},
        {'x', print_hex},
        {'X', print_hex_upper},
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
            int left_padding = 0;
            int right_padding = 0;
            int precision = -1;
            int is_short = 0;
            int is_long = 0;

            if (format[i] == '-')
            {
                i++;
                left_padding = 1;
            }

            if (format[i] == '0')
            {
                i++;
                right_padding = 1;
            }

            while (format[i] >= '0' && format[i] <= '9')
            {
                if (precision == -1 && !left_padding)
                    right_padding = 1;
                precision = (precision * 10) + (format[i] - '0');
                i++;
            }

            if (format[i] == 'h')
            {
                is_short = 1;
                i++;
            }

            if (format[i] == 'l')
            {
                is_long = 1;
                i++;
            }

            while (formats[k].type != 0)
            {
                if (formats[k].type == format[i])
                {
                    formats[k].func(args, buffer, &j, left_padding, right_padding, precision, is_short, is_long);
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

// Print Functions

int print_char(va_list args, char *buffer, int *j, int left_padding, int right_padding, int precision, int is_short, int is_long)
{
    char c = (char)va_arg(args, int);
    int padding_amount = 0;

    if (left_padding)
    {
        buffer[*j] = c;
        (*j)++;
    }

    if (precision != -1)
        padding_amount = precision - 1;

    while (padding_amount > 0)
    {
        buffer[*j] = ' ';
        (*j)++;
        padding_amount--;
    }

    if (!left_padding)
    {
        buffer[*j] = c;
        (*j)++;
    }

    return (1);
}

int print_str(va_list args, char *buffer, int *j, int left_padding, int right_padding, int precision, int is_short, int is_long)
{
