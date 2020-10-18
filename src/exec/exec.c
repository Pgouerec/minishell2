/*
** EPITECH PROJECT, 2019
** # exec.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

void exec_simple_cmd(minishell_t *sh, cmd_t *cmd)
{
    char **env = env_to_array(sh);
    char *path = get_good_path(sh, cmd);
    pid_t pid;

    if (path) {
        if ((pid = fork())) {
            waitpid(pid, NULL, 0);
            free(path);
            free_array(env);
            return;
        }
        if (execve(path, cmd->av, env) == -1) {
            perror("execve");
            exit (0);
        }
        free(path);
    }
    free_array(env);
}

void exec_simple_cmd_nofork(minishell_t *sh, cmd_t *cmd)
{
    char **env = env_to_array(sh);
    char *path = get_good_path(sh, cmd);

    if (execve(path, cmd->av, env) == -1) {
        perror("execve");
        exit (0);
    }
    free(path);
    free_array(env);
}

int fn_semicolon(minishell_t *sh, int x, cmd_t *cmd_a, cmd_t *cmd_b)
{
    if (sh->pipe[x + 1] != NULL && my_strcmp(sh->pipe[x + 1], ";") != 0) {
        exec_simple_cmd(sh, cmd_a);
    } else {
        exec_simple_cmd(sh, cmd_a);
        exec_simple_cmd(sh, cmd_b);
    }
    return (0);
}