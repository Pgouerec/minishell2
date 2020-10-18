/*
** EPITECH PROJECT, 2019
** # my_arrdup.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

char **my_arrdup(char **origin)
{
    char **duplicat;
    int key = 0;

    if (origin[0] == NULL){
        return (NULL);
    }
    duplicat = malloc(sizeof(char *) * (my_arrlen(origin) + 1));
    for (; origin[key] != NULL ; key++) {
        duplicat[key] = my_strdup(origin[key]);
    }
    duplicat[key] = NULL;
    return (duplicat);
}