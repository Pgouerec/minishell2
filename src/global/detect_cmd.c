/*
** EPITECH PROJECT, 2019
** # detect_cmd.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell.h"

int detect_cmd(char *cmd)
{
    char *list_cmd[] = {"cd", "exit", "env", "setenv", "unsetenv", NULL};

    for (int x = 0 ; list_cmd[x] != NULL ; x++)
        if (my_strcmp(cmd, list_cmd[x]) == 0)
            return x;
    return (-1);
}