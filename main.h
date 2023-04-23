#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args, char *buffer, int *j);
int print_str(va_list args, char *buffer, int *j);
int print_percent(char *buffer, int *j);
int print_int(va_list args, char *buffer, int *j);
int print_unsigned_int(va_list args, char *buffer, int *j);
int print_binary(va_list args, char *buffer, int *j);
int print_octal(va_list args, char *buffer, int *j);
int print_hex(va_list args, char *buffer, int *j, int uppercase);
int print_address(va_list args, char *buffer, int *j);
int print_reversed(va_list args, char *buffer, int *j);
int print_rot13(va_list args, char *buffer, int *j);

typedef struct format
{
    char type;
    int (*func)(va_list, char *, int *);
} format_t;

#endif /* MAIN_H */
