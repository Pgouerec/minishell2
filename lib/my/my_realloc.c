/*
** EPITECH PROJECT, 2019
** # my_realloc.c
** File description:
** {description}
*/

#include <stdlib.h>
#include "my.h"

char *my_realloc(char *str, int size)
{
    char *new_str;
    int x;

    if (str == NULL || size < 1)
        return NULL;
    new_str = malloc(sizeof(char) * size + 1);
    for (x = 0 ; x != size && str[x] != '\0' ; x++)
        new_str[x] = str[x];
    if (str[x] == '\0')
        for (x ; x < size ; x++)
            new_str[x] = '\0';
    new_str[x] = '\0';
    free(str);
    return new_str;
}