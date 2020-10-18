/*
** EPITECH PROJECT, 2019
** # cmd.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int my_setenv(minishell_t *sh, cmd_t *cmd)
{
    if (my_isalphanum(cmd->av[1]) != 0) {
        usage_alphanum_input(cmd);
        return (-1);
    }
    if (cmd->ac > 3)
        usage_too_many(cmd);
    if (cmd->ac >= 3)
        env_add_key(sh, my_strdup(cmd->av[1]), my_strdup(cmd->av[2]));
    else if (cmd->ac == 2)
        env_add_key(sh, my_strdup(cmd->av[1]), NULL);
    else {
        renew_path(sh);
        return (-1);
    }
    renew_path(sh);
    return (0);
}

int my_unsetenv(minishell_t *sh, cmd_t *cmd)
{
    if (cmd->ac == 1) {
        my_printf("unsetenv: Too few arguments.\n");
    }
    env_delete_key(sh, cmd->av[1]);
    renew_path(sh);
    return (0);
}

void renew_path(minishell_t *sh)
{
    free_array(sh->path);
    get_all_path(sh);
}