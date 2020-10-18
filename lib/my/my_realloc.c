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
    int x = 0;

    if (str == NULL || size < 1)
        return (NULL);
    new_str = malloc(sizeof(char) * (my_strlen(str) + (size + 1)));
    if (!new_str)
        return (NULL);
    for (; str[x] != '\0' ; x++)
        new_str[x] = str[x];
    for (; x < (my_strlen(str) + size) ; x++)
        new_str[x] = 0;
    free(str);
    return (new_str);
}