/*
** EPITECH PROJECT, 2019
** # read.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

char *get_env_value(minishell_t *sh, char *name)
{
    env_line_t *env = sh->env.first;

    while (env) {
        if (my_strcmp(env->name, name) == 0)
            return (env->value);
        env = env->next;
    }
    return NULL;
}