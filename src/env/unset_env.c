/*
** EPITECH PROJECT, 2019
** # unset_env.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell.h"

char **unset_env(char **av, char **env)
{
    if (av[1] != NULL) {
        if (get_env_line(env, av[1]) != -1)
            env = remove_env(env, av[1]);
        else
            my_printf("mysh: unsetenv: %s: Variable doesn't exist\n");
    } else
        my_printf("mysh: unsetenv: missing argument\n");
    return env;
}