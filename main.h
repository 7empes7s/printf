#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct format
{
    int width;
    int precision;
    int length;
    int flags;
} format_t;

int custom_printf(const char *format, ...);
int print_character(char c);
void parse_format(const char **format_str, format_t *fmt, va_list args);

#endif /* MAIN_H */
