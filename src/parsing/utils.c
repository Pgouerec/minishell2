/*
** EPITECH PROJECT, 2019
** # utils.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int count_path(char *path)
{
    int nb_of_path = 0;

    for (int x = 0 ; path[x] != '\0' ; x++) {
        if (path[x] == ':')
            nb_of_path++;
    }
    nb_of_path++;
    return nb_of_path;
}

int count_arg(char *input)
{
    int nb_of_cmd = 0;

    for (int x = 0 ; input[x] != '\0' ; x++) {
        if (input[x] == ' ')
            nb_of_cmd++;
    }
    nb_of_cmd++;
    return nb_of_cmd;
}

int pipe_str(char *src)
{
    char *pipe[] = {"<", ">", "|", "<<", ">>", ";", NULL};

    for (int x = 0 ; pipe[x] != NULL ; x++) {
        if (my_strcmp(pipe[x], src) == 0)
            return (1);
    }
    return (0);
}

int count_pipe(char **src)
{
    int res = 0;

    for (int x = 0 ; src[x] != NULL ; x++) {
        if (pipe_str(src[x]) != 0)
            res++;
    }
    res++;
    return (res);
}