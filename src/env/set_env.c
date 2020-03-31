/*
** EPITECH PROJECT, 2019
** # set_env.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell.h"

char **set_env(char **av, char **env)
{
    if (av[1] != NULL && av[2] != NULL) {
        if (is_alphanum(av[1]) == 0) {
            print_setenv_error();
            return env;
        }
        if (get_env_line(env, av[1]) != -1)
            env = edit_env(env, av[1], av[2]);
        else
            env = create_env(env, av[1], av[2]);
    } else if (av[1] != NULL && av[2] == NULL) {
        if (is_alphanum(av[1]) == 0) {
            print_setenv_error();
            return env;
        }
        if (get_env_line(env, av[1]) != -1)
            env = edit_empty_env(env, av[1]);
        else
            env = create_empty_env(env, av[1]);
    } else {
        env = printenv(av, env);
    }
    return env;
}

void print_setenv_error(void)
{
    my_printf("setenv: Variable name must ");
    my_printf("contain alphanumeric characters.\n");
}