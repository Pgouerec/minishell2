/*
** EPITECH PROJECT, 2019
** # main.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell.h"

int main(int ac, char **av, char **env)
{
    char **mysh_env = get_env(env);

    get_cmd(mysh_env);
    return (0);
}