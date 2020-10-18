/*
** EPITECH PROJECT, 2019
** # my_isalphanum.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int my_isalphanum(char *name)
{
    if (!name)
        return (-1);
    for (int x = 0 ; name[x] != '\0' ; x++) {
        if ((name[x] < '0' || name[x] > '9')
            && (name[x] < 'A' || name[x] > 'Z')
            && (name[x] < 'a' || name[x] > 'z'))
            return (-1);
    }
    return (0);
}