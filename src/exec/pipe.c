/*
** EPITECH PROJECT, 2019
** # pipe.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int fn_pipe(minishell_t *sh, cmd_t *cmd_a, cmd_t *cmd_b)
{
    pipesys_t psys;
    int fd_tmp = 0;
    cmd_t *cmd_tmp = cmd_a;

    for (int x = 0 ; x < 2 ; x++) {
        init_psys(&psys);
        if (psys.pid == 0) {
            dup2(fd_tmp, 0);
            close(psys.pfd[0]);
            if (x > 0) {
                dup2(psys.pfd[1], 1);
                exec_one_cmd(sh, cmd_b);
            } else
                exec_one_cmd(sh, cmd_a);
        } else {
            close(psys.pfd[1]);
            fd_tmp = psys.pfd[0];
        }
    }
    wait(NULL);
    return (0);
}