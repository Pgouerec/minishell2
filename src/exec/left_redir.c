/*
** EPITECH PROJECT, 2019
** # left_redir.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int left_simple(minishell_t *sh, cmd_t *cmd_a, cmd_t *cmd_b)
{
    char **env = env_to_array(sh);
    char *path = get_good_path(sh, cmd_a);
    pipesys_t psys;

    init_psys(&psys);
    if (file_exist(cmd_b) != 0)
        return (-1);
    psys.pfd[0] = open(cmd_b->name, O_RDONLY);
    if (psys.pid == 0) {
        dup2(psys.pfd[0], 0);
        execve(path, cmd_a->av, env);
    } else {
        close(psys.pfd[0]);
        wait(NULL);
    }
    free(path);
    free_array(env);
    return (0);
}

int left_double(minishell_t *sh, cmd_t *cmd_a, cmd_t *cmd_b)
{
    return (0);
}

int file_exist(cmd_t *cmd)
{
    if (access(cmd->name, F_OK) == 0) {
        return (0);
    } else {
        error_no_such_file_o_dir_bis(cmd);
        return (1);
    }
    return (-1);
}