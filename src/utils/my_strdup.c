/*
** EPITECH PROJECT, 2019
** # my_strdup.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

char *my_strdup(char *src)
{
    char *res = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    for (; src[i] != '\0'; i++)
        res[i] = src[i];
    res[i] = '\0';
    return (res);
}