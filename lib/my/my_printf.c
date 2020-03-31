/*
** EPITECH PROJECT, 2019
** # my_printf.c
** File description:
** {description}
*/

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include "my.h"

int my_tag_match(char chr);

int my_printf(char *s, ...)
{
    int nbfunction = 14;
    va_list args;
    void (*tag[])(char *str, va_list args) = {disp_int, disp_int, disp_chr,
                                            disp_str, disp_uint, disp_astr,
                                            disp_oct, disp_bin,
                                            disp_hexs, disp_hexh, disp_prcnt,
                                            };

    va_start(args, s);
    for (int i = 0 ; s[i] != '\0' ; i++) {
        if (s[i] == '%') {
            if (my_tag_match(s[i + 1]) < nbfunction) {
                tag[my_tag_match(s[i + 1])](s, args);
                i++;
            } else
                my_putchar(s[i]);
        } else
            my_putchar(s[i]);
    }
    va_end(args);
}

int my_tag_match(char chr)
{
    char str[] = "dicsupobxX%";

    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (chr == str[i])
            return (i);
    }
}