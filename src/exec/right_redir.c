/*
** EPITECH PROJECT, 2019
** # right_redir.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int right_simple(minishell_t *sh, cmd_t *cmd_a, cmd_t *cmd_b)
{
    pipesys_t psys;

    create_file(&psys, cmd_b);
    init_psys(&psys);
    return redirect_data(sh, cmd_a, &psys);
}

int right_double(minishell_t *sh, cmd_t *cmd_a, cmd_t *cmd_b)
{
    pipesys_t psys;

    create_file_append(&psys, cmd_b);
    init_psys(&psys);
    return redirect_data(sh, cmd_a, &psys);
}

int redirect_data(minishell_t *sh, cmd_t *cmd, pipesys_t *psys)
{
    char **env = env_to_array(sh);
    char *path = get_good_path(sh, cmd);

    if (psys->pid == 0) {
        close(psys->pfd[0]);
        dup2(psys->pfd[1],1);
        close(psys->pfd[1]);
        execve(path, cmd->av, env);
    } else {
        close(psys->pfd[1]);
        psys->nc = read(psys->pfd[0], psys->data, sizeof(psys->data));
        psys->data[psys->nc] = '\0';
        fputs(psys->data, psys->file);
        wait(NULL);
        fclose(psys->file);
    }
    free(path);
    free_array(env);
    return (0);
}