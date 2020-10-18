/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** Compare to string.
*/

#include "my.h"
#include <stddef.h>

int my_strcmp(char const *s1, char const *s2)
{
    int x = 0;

    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return -1;
    if (my_strlen(s1) != my_strlen(s2))
        return 1;
    for (x ; s1[x] != '\0' && s2[x] != '\0' ; x++) {
        if (s1[x] != s2[x])
            return 1;
    }
    return 0;
}