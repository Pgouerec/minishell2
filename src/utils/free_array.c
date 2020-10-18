/*
** EPITECH PROJECT, 2019
** # free_array.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int free_array(char **arr)
{
    int rel = 0;

    if (arr == NULL || arr[0] == NULL)
        return (-1);
    for (int x = 0 ; arr[x] != NULL ; x++) {
        if (arr[x])
            free(arr[x]);
    }
    free(arr);
    return (rel);
}