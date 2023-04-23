#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);

typedef struct format
{
    char type;
    int (*func)(va_list, char *, int *);
} format_t;

#endif /* MAIN_H */
