#include "main.h"

int print_address(va_list l, flag_t *f)
{
    char *str;
    uintptr_t p = va_arg(l, uintptr_t);

    register int count = 0;

    (void)f;

    if (!p)
        return (_puts("(nil)"));
    str = convert(p, 16, 1);
    count += _puts("0x");
    count += _puts(str);
    return (count);
}
