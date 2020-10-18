/*
** EPITECH PROJECT, 2019
** # init_global.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int init_global(minishell_t *sh, char **env)
{
    cmd_table_init(&sh->cmd);
    env_table_init(&sh->env);
    init_env(sh, env);
    if (get_all_path(sh) != 0)
        return (-1);
    return (0);
}

void cmd_table_init(cmd_table_t *cmd_table)
{
    cmd_table->first = NULL;
    cmd_table->last = NULL;
}

void env_table_init(env_t *env_table)
{
    env_table->first = NULL;
    env_table->last = NULL;
}