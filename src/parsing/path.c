/*
** EPITECH PROJECT, 2019
** # path.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int get_all_path(minishell_t *sh)
{
    char *simple_path;

    simple_path = get_env_value(sh, "PATH");
        if (simple_path == NULL)
            default_path(sh);
        else
            path_parsing(simple_path, sh);
    return (0);
}

int path_parsing(char *path, minishell_t *sh)
{
    sh->path = malloc(sizeof(char *) * (count_path(path) + 1));
    char *tmp;
    int c = 0;
    int f = 0;
    int p = 0;
    int size = my_strlen(path);

    for (int x = 0 ; x < size ; x = c + 1) {
        for (c = x ; path[c] != ':' && path[c] != '\0' ; c++);
        tmp = malloc(sizeof(char) * (c - x + 3));
        f = 0;
        for (c = x ; path[c] != ':' && path[c] != '\0' ; c++) {
            tmp[f] = path[c];
            f++;
            tmp[f] = '\0';
        }
        sh->path[p] = my_strdup(tmp);
        free(tmp);
        p++;
    }
    sh->path[p] = NULL;
    return (0);
}

int default_path(minishell_t *sh)
{
    sh->path = malloc(sizeof(char *) * 2);

    if (!sh->path)
        return (-1);
    sh->path[0] = my_strdup("/usr/bin");
    sh->path[1] = NULL;
    return (0);
}