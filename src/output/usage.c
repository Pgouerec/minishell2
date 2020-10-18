/*
** EPITECH PROJECT, 2019
** # usage.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

void usage_too_many(cmd_t *cmd)
{
    my_printf("%s: Too many arguments.\n", cmd->name);
}

void usage_unknown_user(char *user)
{
    my_printf("Unknown user: %s.\n", user);
}

void usage_alphanum_input(cmd_t *cmd)
{
    my_printf("%s: Variable name must contain ", cmd->name);
    my_printf("alphanumeric characters.\n");
}

void usage_not_dir(cmd_t *cmd)
{
    my_printf("%s: Not a directory.\n", cmd->av[1]);
}