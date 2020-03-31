/*
** EPITECH PROJECT, 2019
** # my_dec_to_bin.c
** File description:
** {description}
*/

#include <stdlib.h>
#include "my.h"

char *my_dec_to_bin(long dec)
{
    char *str = malloc(sizeof(char) * 20);
    unsigned long res = 0;
    int i = 0;

    for (i ; dec != 0 ; i++) {
        res = dec % 2;
        dec = dec / 2;
        str[i] = res + '0';
    }
    return (my_revstr(str));
}