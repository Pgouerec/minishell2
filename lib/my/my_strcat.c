/*
** EPITECH PROJECT, 2019
** # my_strcat.c
** File description:
** Concatenate two strings.
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    int l = my_strlen(src);
    int a = 0;
    char *str = malloc(sizeof(char) * i + l + 1);

    for (a ; dest[a] != '\0' ; a++)
        str[a] = dest[a];
    for (int b = 0 ; src[b] != '\0' ; b++) {
        str[a] = src[b];
        a++;
    }
    return (str);
}