/*
** EPITECH PROJECT, 2019
** # exit.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell.h"

char **my_exit(char **av, char **env)
{
    int ac = count_double_array(av);

    if (ac <= 1)
        exit(0);
    else if (ac > 2) {
        my_printf("exit: Expression Syntax.\n");
    } else if (ac == 2) {
        if (my_str_isnum(av[1]) == 1)
            exit (my_getnbr(av[1]));
        else {
            my_printf("exit: Expression Syntax.\n");
        }
    }
    return env;
}