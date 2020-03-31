/*
** EPITECH PROJECT, 2019
** # print_env.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell.h"

char **printenv(char **av, char **env)
{
    for (int x = 0 ; env[x] != NULL ; x++)
        my_printf("%s\n", env[x]);
    return env;
}