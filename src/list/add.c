/*
** EPITECH PROJECT, 2019
** # add.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int add_cmd(minishell_t *sh, char *name, int ac, char **av)
{
    cmd_t *new = malloc(sizeof(cmd_t));

    if (!new)
        return (-1);
    new->name = my_strdup(name);
    new->ac = ac;
    new->av = my_arrdup(av);
    new->next = NULL;
    if (sh->cmd.last)
        sh->cmd.last->next = new;
    else
        sh->cmd.first = new;
    sh->cmd.last = new;
    free_array(av);
    return (0);
}

int add_env_line(minishell_t *sh, char *name, char *value)
{
    env_line_t *new = malloc(sizeof(env_line_t));

    if (!new)
        return (-1);
    new->name = name;
    if (value == NULL)
        new->value = NULL;
    else
        new->value = value;
    new->next = NULL;
    if (sh->env.last)
        sh->env.last->next = new;
    else
        sh->env.first = new;
    sh->env.last = new;
    return (0);
}