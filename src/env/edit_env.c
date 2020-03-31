/*
** EPITECH PROJECT, 2019
** # edit_env.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell.h"

char **remove_env(char **env, char *name)
{
    int a = 0;
    int b = 0;
    int len = 0;
    char **arr = malloc(sizeof(char *) * my_arrlen(env));

    for (a ; env[a] != NULL ; a++) {
        if (a != get_env_line(env, name)) {
            len = my_strlen(env[a]);
            arr[b] = malloc(sizeof(char) * len + 1);
            arr[b] = env[a];
            b++;
        }
    }
    return arr;
}

char **create_env(char **env, char *name, char *value)
{
    int a = 0;
    int len = 0;
    char **arr = malloc(sizeof(char *) * my_arrlen(env) + 1);
    char *str;

    for (a ; env[a] != NULL ; a++) {
        len = my_strlen(env[a]);
        arr[a] = malloc(sizeof(char) * len + 1);
        arr[a] = env[a];
    }
    str = env_name_cat(env, name, value);
    arr[a] = str;
    arr[a + 1] = NULL;

    return arr;
}

char **create_empty_env(char **env, char *name)
{
    int a = 0;
    int len = 0;
    char **arr = malloc(sizeof(char *) * my_arrlen(env) + 1);
    char *str;

    for (a ; env[a] != NULL ; a++) {
        len = my_strlen(env[a]);
        arr[a] = malloc(sizeof(char) * len + 1);
        arr[a] = env[a];
    }
    str = env_name_cat(env, name, NULL);
    arr[a] = str;
    arr[a + 1] = NULL;

    return arr;
}

char **edit_env(char **env, char *name, char *value)
{
    int a = 0;
    int len = 0;
    int line = get_env_line(env, name);
    char **arr = malloc(sizeof(char *) * my_arrlen(env) + 1);
    char *str;

    str = env_name_cat(env, name, value);
    for (a ; env[a] != NULL ; a++) {
        if (a != line) {
            len = my_strlen(env[a]);
            arr[a] = malloc(sizeof(char) * len + 1);
            arr[a] = env[a];
        } else {
            len = my_strlen(str);
            arr[a] = malloc(sizeof(char) * len + 1);
            arr[a] = str;
        }
    }
    arr[a + 1] = NULL;
    return arr;
}

char **edit_empty_env(char **env, char *name)
{
    int a = 0;
    int len = 0;
    int line = get_env_line(env, name);
    char **arr = malloc(sizeof(char *) * my_arrlen(env) + 1);
    char *str;

    str = env_name_cat(env, name, NULL);
    for (a ; env[a] != NULL ; a++) {
        if (a != line) {
            len = my_strlen(env[a]);
            arr[a] = malloc(sizeof(char) * len + 1);
            arr[a] = env[a];
        } else {
            len = my_strlen(str);
            arr[a] = malloc(sizeof(char) * len + 1);
            arr[a] = str;
        }
    }
    arr[a + 1] = NULL;
    return arr;
}