/*
** EPITECH PROJECT, 2019
** # utils.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int get_builtin_num(char *name)
{
    char *builtin_list[] = {"cd", "env", "unsetenv", "setenv", NULL};

    for (int x = 0 ; builtin_list[x] != NULL ; x++)
        if (my_strcmp(name, builtin_list[x]) == 0)
            return (x);
    return (-1);
}

int get_pipe_num(char *pipe)
{
    char *pipe_list[] = {">", ">>", "<", "<<", "|", ";", NULL};

    for (int x = 0 ; pipe_list[x] != NULL ; x++)
        if (my_strcmp(pipe, pipe_list[x]) == 0)
            return (x);
    return (-1);
}

int init_psys(pipesys_t *psys)
{
    if (pipe(psys->pfd) == -1)
        return (-1);
    if ((psys->pid = fork()) == -1)
        return (-1);
    return (0);
}