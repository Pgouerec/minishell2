/*
** EPITECH PROJECT, 2019
** # my_dec_to_oct.c
** File description:
** {description}
*/

#include <stdlib.h>
#include "my.h"

char *my_dec_to_oct(long dec)
{
    char *str = malloc(sizeof(char) * 20);
    unsigned long res = 0;
    int i = 0;

    for (i ; dec != 0 ; i++) {
        res = dec % 8;
        dec = dec / 8;
        str[i] = res + '0';
    }
    return (my_revstr(str));
}