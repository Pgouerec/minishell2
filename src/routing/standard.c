/*
** EPITECH PROJECT, 2019
** # standard.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int no_pipe_routing(minishell_t *sh)
{
    int (*builtin[])(minishell_t *sh, cmd_t *cmd) = {change_dir, print_env, 
                                                    my_unsetenv, my_setenv};
    cmd_t *cmd = sh->cmd.first;
    int ccmd;

    if (cmd == NULL)
        return (-1);
    while (cmd) {
        ccmd = get_builtin_num(cmd->name);
        if (ccmd != -1)
            return builtin[ccmd](sh, cmd);
        else
            exec_simple_cmd(sh, cmd);
        cmd = cmd->next;
    }
    return (0);
}

int pipe_routing(minishell_t *sh)
{
    int (*route[])(minishell_t *sh, cmd_t *cmd_a, cmd_t *cmd_b) = {right_simple,
                                                right_double, left_simple,
                                                left_double, fn_pipe};
    int ppnum = 0;
    cmd_t *cmd = sh->cmd.first;

    for (int x = 0 ; sh->pipe[x] != NULL ; x++) {
        ppnum = get_pipe_num(sh->pipe[x]);
        if (ppnum == 5)
            fn_semicolon(sh, x, cmd, cmd->next);
        else
            route[ppnum](sh, cmd, cmd->next);
        cmd = cmd->next;

        if (cmd == NULL)
            break;
    }
    return (0);
}

int exec_one_cmd(minishell_t *sh, cmd_t *cmd)
{
    int (*builtin[])(minishell_t *sh, cmd_t *cmd) = {change_dir, print_env, 
                                                    my_unsetenv, my_setenv};
    int ccmd = 0;

    ccmd = get_builtin_num(cmd->name);
    if (ccmd != -1)
        return builtin[ccmd](sh, cmd);
    else
        exec_simple_cmd_nofork(sh, cmd);
    return (0);
}