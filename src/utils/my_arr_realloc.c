/*
** EPITECH PROJECT, 2019
** # my_arr_realloc.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

char **my_arr_realloc(char **origin, int size)
{
    char **duplicat;
    int orisize = 0;
    int key = 0;

    if (!origin)
        return (NULL);
    orisize = my_arrlen(origin);
    duplicat = malloc(sizeof(char *) * (my_arrlen(origin) + size));
    for (; key < (orisize + size) ; key++) {
        if (duplicat[key] != NULL)
            my_strcpy(duplicat[key], origin[key]);
        else
            duplicat[key] = NULL;
    }
    return (duplicat);
}