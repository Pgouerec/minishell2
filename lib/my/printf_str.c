/*
** EPITECH PROJECT, 2019
** # print_f_str.c
** File description:
** {description}
*/

#include <stdarg.h>
#include "my.h"

void disp_chr(char *s, va_list args)
{
    int chr;

    chr = va_arg(args, int);
    my_putchar(chr);
}

void disp_str(char *s, va_list args)
{
    char *str;

    str = va_arg(args, char *);
    my_putstr(str);
}

void disp_uint(char *s, va_list args)
{
    unsigned int i;

    i = va_arg(args, unsigned int);
    my_putnbr(i);
}

void disp_astr(char *s, va_list args)
{
    char *str;

    str = va_arg(args, char *);
    my_putstr("0x");
    my_putstr(my_dec_to_hex((unsigned long int)str, 1));
}