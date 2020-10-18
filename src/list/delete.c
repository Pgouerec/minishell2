/*
** EPITECH PROJECT, 2019
** # delete.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

void delete_cmd_table(minishell_t *sh)
{
    cmd_t *tmp;
    cmd_t *cmd = sh->cmd.first;

    while (cmd) {
        tmp = cmd;
        free(tmp->name);
        free_array(tmp->av);
        cmd = cmd->next;
        free(tmp);
    }
    sh->cmd.first = NULL;
    sh->cmd.last = NULL;
}

void delete_env_table(minishell_t *sh)
{
    env_line_t *tmp;
    env_line_t *env = sh->env.first;

    while (env) {
        tmp = env;
        env = env->next;
        free_node_env(tmp);
    }
    sh->env.first = NULL;
    sh->env.last = NULL;
}

void free_node_env(env_line_t *env)
{
    (env->name != NULL) ? free(env->name) : 0;
    (env->value != NULL) ? free(env->value) : 0;
    free(env);
}