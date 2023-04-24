#include "main.h"

/**
 * fetch_print_function - selects the appropriate printing function
 * depending on the conversion specifier passed to custom_printf
 * @s: character that holds the conversion specifier
 * Description: the function loops through the structs array
 * func_arr[] to find a match between the specifier passed to custom_printf
 * and the first element of the struct, and then the appropriate
 * printing function
 * Return: a pointer to the matching printing function
 */
int (*fetch_print_function(char s))(va_list, flag_t *)
{
    ph func_arr[] = {
        {'i', print_int},
        {'s', print_string},
        {'c', print_char},
        {'d', print_int},
        {'u', print_unsigned},
        {'x', print_hex},
        {'X', print_hex_big},
        {'b', print_binary},
        {'o', print_octal},
        {'R', print_rot13},
        {'r', print_rev},
        {'S', print_bigS},
        {'p', print_address},
        {'%', print_percent}
        };
    int flags = 14;

    register int i;

    for (i = 0; i < flags; i++)
        if (func_arr[i].c == s)
            return (func_arr[i].f);
    return (NULL);
}
