#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * custom_printf - generates output based on given format
 * @fmt: format string containing characters and specifiers
 * Description: this function calls the fetch_print_function() that will
 * identify the appropriate printing function to use based on the conversion
 * specifiers within fmt
 * Return: length of the formatted output string
 */
int custom_printf(const char *fmt, ...)
{
    int (*print_func)(va_list, flag_t *);
    const char *ptr;
    va_list args;
    flag_t flags = {0, 0, 0};

    int char_count = 0;

    va_start(args, fmt);
    if (!fmt || (fmt[0] == '%' && !fmt[1]))
        return (-1);
    if (fmt[0] == '%' && fmt[1] == ' ' && !fmt[2])
        return (-1);
    for (ptr = fmt; *ptr; ptr++)
    {
        if (*ptr == '%')
        {
            ptr++;
            if (*ptr == '%')
            {
                char_count += print_char('%');
                continue;
            }
            while (check_flag(*ptr, &flags))
                ptr++;
            print_func = fetch_print_function(*ptr);
            char_count += (print_func)
                ? print_func(args, &flags)
                : custom_printf("%%%c", *ptr);
        }
        else
            char_count += print_char(*ptr);
    }
    print_char(-1);
    va_end(args);
    return (char_count);
}
