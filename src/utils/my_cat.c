/*
** EPITECH PROJECT, 2019
** # my_cat.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

char *my_cat(char *dest, char *src)
{
    int a = 0;
    int b = 0;

    if (src == NULL)
        return (dest);
    if (dest == NULL)
        return (NULL);
    a = my_strlen(dest);
    for (; src[b] != '\0' ; b++) {
        dest[a] = src[b];
        a++;
    }
    dest[a] = '\0';
    return (dest);
}