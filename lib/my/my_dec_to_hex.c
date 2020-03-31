/*
** EPITECH PROJECT, 2019
** # my_dec_to_hex.c
** File description:
** {description}
*/

#include <stdlib.h>
#include "my.h"

char hex(int l, int size);

char *my_dec_to_hex(long dec, int size)
{
    char *str = malloc(sizeof(char) * 20);
    unsigned long res = 0;
    int i = 0;

    for (i ; dec != 0 ; i++) {
        res = dec % 16;
        dec = dec / 16;
        if (size == 1)
            str[i] = hex(res, size);
        else if (size == 0)
            str[i] = hex(res, size);
    }
    return (my_revstr(str));
}

char hex(int l, int size)
{
    char *hexs = "0123456789abcdef";
    char *hexh = "0123456789ABCDEF";

    if (size == 1){
        for (int i = 0 ; hexs[i] != '\0' ; i++)
            if (i == l)
                return (hexs[i]);
    } else if (size == 0) {
        for (int i = 0 ; hexh[i] != '\0' ; i++)
            if (i == l)
                return (hexh[i]);
    }
}