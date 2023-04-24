#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to custom_printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
    int plus;
    int space;
    int hash;
} flag_t;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to custom_printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printHandler
{
    char c;
    int (*f)(va_list ap, flag_t *f);
} ph;

/* print_nums */
int print_int(va_list l, flag_t *f);
void print_number(int n);
int print_unsigned(va_list l, flag_t *f);
int count_digit(int i);

/* print_bases */
int print_hex(va_list l, flag_t *f);
int print_hex_big(va_list l, flag_t *f);
int print_binary(va_list l, flag_t *f);
int print_octal(va_list l, flag_t *f);

/* converter */
char *convert(unsigned long int num, int base, int lowercase);

/* custom_printf */
int custom_printf(const char *fmt, ...);

/* fetch_print_function */
int (*fetch_print_function(char s))(va_list, flag_t *);

/* check_flag */
int check_flag(char s, flag_t *f);

/* print_alpha */
int print_string(va_list l, flag_t *f);
int print_char(va_list l, flag_t *f);

/* write_funcs */
int print_char(char c);
int _puts(char *str);

/* print_custom */
int print_rot13(va_list l, flag_t *f);
int print_rev(va_list l, flag_t *f);
int print_bigS(va_list l, flag_t *f);

/* print_address */
int print_address(va_list l, flag_t *f);

/* print_percent */
int print_percent(va_list l, flag_t *f);

#endif
