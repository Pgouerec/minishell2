/*
** EPITECH PROJECT, 2019
** # edit.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int env_exist_key(minishell_t *sh, char *name)
{
    env_line_t *env = sh->env.first;

    while (env) {
        if (my_strcmp(env->name, name) == 0)
            return (1);
        env = env->next;
    }
    return (0);
}

int env_delete_key(minishell_t *sh, char *name)
{
    env_line_t *tmp = sh->env.first;
    env_line_t *prev = NULL;

    if (tmp != NULL && my_strcmp(tmp->name, name) == 0) {
        sh->env.first = tmp->next;
        free_node_env(tmp);
        return (0);
    }
    while (tmp != NULL && my_strcmp(tmp->name, name) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return (-1);
    if (tmp->next == NULL)
        sh->env.last = prev;
    prev->next = tmp->next;
    free_node_env(tmp);
    return (0);
}

int env_add_key(minishell_t *sh, char *name, char *value)
{
    if (env_exist_key(sh, name) == 1) {
        env_delete_key(sh, name);
        add_env_line(sh, name, value);
    } else {
        add_env_line(sh, name, value);
    }
    return (0);
}