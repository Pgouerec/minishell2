/*
** EPITECH PROJECT, 2019
** # init.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

int init_env(minishell_t *sh, char **env)
{
    int x = 0;
    char *name = NULL;
    char *value = NULL;

    while (!env_exist(env, x)) {
        name = env_name(env, x);
        value = env_value(env, x);
        if (add_env_line(sh, name, value))
            break;
        x++;
    }
    return (0);
}

int env_exist(char **env, int l)
{
    if (env[l] == NULL)
        return (-1);
    return (0);
}

char *env_name(char **env, int l)
{
    char *tmp = malloc(sizeof(char) * my_strlen(env[l]));
    char *name;
    int i = 0;
    int x = 0;

    for (; env[l][x] != '=' && env[l][x] != '\0' ; x++) {
        tmp[i] = env[l][x];
        i++;
    }
    tmp[i] = '\0';
    name = my_strdup(tmp);
    free(tmp);
    return name;
}

char *env_value(char **env, int l)
{
    char *tmp = malloc(sizeof(char) * my_strlen(env[l]));
    char *value;
    int i = 0;
    int x = 0;

    for (; env[l][x] != '=' && env[l][x] != '\0' ; x++);
    x++;
    for (; env[l][x] != '\0' ; x++) {
        tmp[i] = env[l][x];
        i++;
    }
    tmp[i] = '\0';
    value = my_strdup(tmp);
    free(tmp);
    return value;
}