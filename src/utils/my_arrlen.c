/*
** EPITECH PROJECT, 2019
** # my_arrlen.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int my_arrlen(char **arr)
{
    int len = 0;

    if (!arr[0])
        return (-1);
    for (; arr[len] != NULL ; len++);
    return (len);
}