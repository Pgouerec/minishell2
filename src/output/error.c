/*
** EPITECH PROJECT, 2019
** # error.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

void error_not_found(cmd_t *cmd)
{
    my_printf("%s: Command not found.\n", cmd->name);
}

void error_denied(cmd_t *cmd)
{
    my_printf("%s: Permission denied.\n", cmd->av[1]);
}

void error_exec_denied(cmd_t *cmd)
{
    my_printf("%s: Permission denied.\n", cmd->name);
}

void error_no_such_file_o_dir(cmd_t *cmd)
{
    my_printf("%s: No such file of directory.\n", cmd->av[1]);
}

void error_no_such_file_o_dir_bis(cmd_t *cmd)
{
    my_printf("%s: No such file of directory.\n", cmd->name);
}