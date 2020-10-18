/*
** EPITECH PROJECT, 2019
** # main.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int main(int ac, char **av, char **env)
{
    int rel = 0;
    minishell_t sh;

    if (init_global(&sh, env) != 0)
        return (84);
    rel = prompt(&sh);
    if (global_free(&sh) != 0)
        return (84);
    return (0);
}