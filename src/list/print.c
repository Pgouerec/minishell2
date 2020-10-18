/*
** EPITECH PROJECT, 2019
** # print.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int print_env(minishell_t *sh, cmd_t *cmd)
{
    env_line_t *env = sh->env.first;

    while (env) {
        if (env->value != NULL)
            my_printf("%s=%s\n", env->name, env->value);
        else
            my_printf("%s=\n", env->name);
        env = env->next;
    }
    if (cmd->name)
        return (0);
    return (0);
}