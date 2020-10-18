/*
** EPITECH PROJECT, 2019
** # free_global.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int global_free(minishell_t *sh)
{
    delete_cmd_table(sh);
    delete_env_table(sh);
    if (free_array(sh->path) != 0)
        return (-1);
    return (0);
}