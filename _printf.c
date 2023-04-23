#include "main.h"

/**
 * print_character - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_character(char c)
{
    return (write(1, &c, 1));
}

/**
 * display_char - Print a character
 * @args: list of arguments
 * @fmt: format structure
 * Return: number of characters printed
 */
int display_char(va_list args, format_t *fmt)
{
    (void) fmt;
    return (print_character(va_arg(args, int)));
}

/* Implement other helper functions for each conversion specifier here */

/**
 * parse_format - parse the format string for flags, width, precision, length
 * @format_str: pointer to the format string
 * @fmt: pointer to the format structure to fill
 * @args: list of arguments
 */
void parse_format(const char **format_str, format_t *fmt, va_list args)
{
    /* Parse flags, width, precision, length here */

    /* Example flag parsing */
    if (**format_str == '-')
    {
        fmt->flags |= 1;
        (*format_str)++;
    }

    /* Parse other elements of format string */
}

/**
 * custom_printf - custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int custom_printf(const char *format, ...)
{
    va_list args;
    int char_count = 0;
    format_t fmt;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            parse_format(&format, &fmt, args);
            switch (*format)
            {
                case 'c':
                    char_count += display_char(args, &fmt);
                    break;
                /* Handle other conversion specifiers here */
                default:
                    return (-1);
            }
        }
        else
        {
            print_character(*format);
           
