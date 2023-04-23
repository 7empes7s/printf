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
        {'u', print_unsigned_int},
        {'o', print_octal},
        {'x', print_hex},
        {'X', print_hex_upper},
        {'p', print_address},
        {'r', print_reversed},
        {'R', print_rot13},
        {0, NULL}
    };

    va_start(args, format);
    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            int k = 0;

            // flags
            int precision = -1;
            int width = -1;
            int is_zero_padded = 0;
            int is_left_justified = 0;
            int is_space_signed = 0;
            int is_plus_signed = 0;
            int is_hash_flag_set = 0;
            while (1)
            {
                if (format[i] == '-')
                    is_left_justified = 1;
                else if (format[i] == '+')
                    is_plus_signed = 1;
                else if (format[i] == ' ')
                    is_space_signed = 1;
                else if (format[i] == '0')
                    is_zero_padded = 1;
                else if (format[i] == '#')
                    is_hash_flag_set = 1;
                else
                    break;
                i++;
            }

            // width
            if (format[i] >= '1' && format[i] <= '9')
            {
                width = 0;
                while (format[i] >= '0' && format[i] <= '9')
                {
                    width = width * 10 + (format[i] - '0');
                    i++;
                }
            }
            else if (format[i] == '*')
            {
                width = va_arg(args, int);
                i++;
            }

            // precision
            if (format[i] == '.')
            {
                i++;
                if (format[i] >= '0' && format[i] <= '9')
                {
                    precision = 0;
                    while (format[i] >= '0' && format[i] <= '9')
                    {
                        precision = precision * 10 + (format[i] - '0');
                        i++;
                    }
                }
                else if (format[i] == '*')
                {
                    precision = va_arg(args, int);
                    i++;
                }
                else
                    precision = 0;
            }

            // length modifier
            int is_long_long_modifier = 0;
            int is_long_modifier = 0;
            int is_short
