/*
** EPITECH PROJECT, 2019
** # debug.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

void debug_cmd(cmd_t *cmd)
{
    my_printf("# COMMAND ############\n");
    my_printf("Name: %s\n", cmd->name);
    my_printf("Args: %d\n", cmd->ac);
    for (int x = 0 ; cmd->av[x] != NULL ; x++)
        my_printf("[%d] %s\n", x, cmd->av[x]);
    my_printf("######################\n");
}

void debug_path(minishell_t *sh)
{
    my_printf("# PATH ###############\n");
    for (int x = 0 ; sh->path[x] != NULL ; x++)
        my_printf("[%d] %s\n", x, sh->path[x]);
    my_printf("######################\n");
}

void debug_array(char *name, char **arr)
{
    my_printf("# %s\n", name);
    my_printf("# ARRAY ##############\n");
    for (int x = 0 ; arr[x] != NULL ; x++)
        my_printf("[%d] %s\n", x, arr[x]);
    my_printf("######################\n");
}