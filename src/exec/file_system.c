/*
** EPITECH PROJECT, 2019
** # file_system.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int create_file(pipesys_t *psys, cmd_t *cmd)
{
    psys->file = fopen(cmd->name, "w");
    if (psys->file == NULL)
        return (-1);
    return (0);
}

int create_file_append(pipesys_t *psys, cmd_t *cmd)
{
    psys->file = fopen(cmd->name, "a");
    if (psys->file == NULL)
        return (-1);
    return (0);
}