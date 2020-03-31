/*
** EPITECH PROJECT, 2019
** # print_int.c
** File description:
** {description}
*/

#include <stdarg.h>
#include "my.h"

void disp_int(char *s, va_list args)
{
    int i;

    i = va_arg(args, int);
    my_putnbr(i);
}

void disp_oct(char *s, va_list args)
{
    long oct;

    oct = va_arg(args, long);
    my_putstr(my_dec_to_oct(oct));
}

void disp_bin(char *s, va_list args)
{
    long bin;

    bin = va_arg(args, long);
    my_putstr(my_dec_to_bin(bin));
}

void disp_hexs(char *s, va_list args)
{
    long hexs;

    hexs = va_arg(args, long);
    my_putstr(my_dec_to_hex(hexs, 1));
}

void disp_hexh(char *s, va_list args)
{
    long hexh;

    hexh = va_arg(args, long);
    my_putstr(my_dec_to_hex(hexh, 0));
}