/*
** EPITECH PROJECT, 2019
** # read_path.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell.h"

char **envpath_to_path(char *path)
{
    char **output = malloc(sizeof(char *) * 50);
    char *tmp;
    int c = 0;
    int f = 0;
    int p = 0;
    int size = my_strlen(path);

    for (int x = 0 ; x < size ; x = c + 1) {
        for (c = x ; path[c] != ':' && path[c] != '\0' ; c++);
        tmp = malloc(sizeof(char) * c -x + 2);
        f = 0;
        for (c = x ; path[c] != ':' && path[c] != '\0' ; c++) {
            tmp[f] = path[c];
            f++;
            tmp[f] = '/';
        }
        output[p] = tmp;
        p++;
    }
    return (output);
}