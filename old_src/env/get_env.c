/*
** EPITECH PROJECT, 2019
** # get_env.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell.h"

char **get_env(char **env)
{
    int a = 0;
    int len = 0;
    char **arr = malloc(sizeof(char *) * my_arrlen(env) + 1);

    for (a ; env[a] != NULL ; a++) {
            len = my_strlen(env[a]);
            arr[a] = malloc(sizeof(char) * len + 1);
            arr[a] = env[a];
    }
    arr[a] = NULL;
    return arr;
}