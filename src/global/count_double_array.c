/*
** EPITECH PROJECT, 2019
** # count_double_array.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell.h"

int count_double_array(char **arr)
{
    int x = 0;

    for (x ; arr[x] != NULL ; x++);
    return x;
}