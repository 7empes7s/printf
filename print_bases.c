#include "main.h"

int print_hex(va_list l, flag_t *f)
{
    unsigned int num = va_arg(l, unsigned int);
    char *str = convert(num, 16, 1);
    int count = 0;

    if (f->hash == 1 && str[0] != '0')
        count += _puts("0x");
    count += _puts(str);
    return (count);
}

int print_hex_big(va_list l, flag_t *f)
{
    unsigned int num = va_arg(l, unsigned int);
    char *str = convert(num, 16, 0);
    int count = 0;

    if (f->hash == 1 && str[0] != '0')
        count += _puts("0X");
    count += _puts(str);
    return (count);
}

int print_binary(va_list l, flag_t *f)
{
    unsigned int num = va_arg(l, unsigned int);
    char *str = convert(num, 2, 0);

    (void)f;
    return (_puts(str));
}

int print_octal(va_list l, flag_t *f)
{
    unsigned int num = va_arg(l, unsigned int);
    char *str = convert(num, 8, 0);
    int count = 0;

    if (f->hash == 1 && str[0] != '0')
        count += _putchar('0');
    count += _puts(str);
    return (count);
}
