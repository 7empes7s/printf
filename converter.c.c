#include "main.h"

/**
 * transform - transforms a number and base into a string
 * @num: input number
 * @base: input base
 * @lowercase: flag indicating if hexa values should be lowercase
 * Return: result string
 */
char *transform(unsigned long int num, int base, int lowercase)
{
    static char *representation;
    static char buffer[50];
    char *pointer;

    representation = (lowercase)
        ? "0123456789abcdef"
        : "0123456789ABCDEF";
    pointer = &buffer[49];
    *pointer = '\0';
    do {
        *--pointer = representation[num % base];
        num /= base;
    } while (num != 0);

    return (pointer);
}
