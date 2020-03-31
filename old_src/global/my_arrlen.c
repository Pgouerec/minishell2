/*
** EPITECH PROJECT, 2019
** # my_arrlen.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell.h"

int my_arrlen(char **arr)
{
    int x = 0;

    for (x ; arr[x] != NULL ; x++);
    return x;
}