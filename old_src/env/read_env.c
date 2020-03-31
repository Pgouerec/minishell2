/*
** EPITECH PROJECT, 2019
** # read_env.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell.h"

char *get_env_value(char **env, char *name)
{
    char *value;
    int i = 0;
    int x = 0;

    for (i ; env[i] != NULL ; i++) {
        for (x ; x < my_strlen(name) && env[i][x] == name[x] ; x++);
            if (x == my_strlen(name)) {
                value = read_env_line(env, name, i);
                return value;
            } else {
                x = 0;
            }
    }
}

int get_env_line(char **env, char *name)
{
    char *value;
    int i = 0;
    int x = 0;

    for (i ; env[i] != NULL ; i++) {
        for (x ; x < my_strlen(name) && env[i][x] == name[x] ; x++);
            if (x == my_strlen(name)) {
                return i;
            } else {
                x = 0;
            }
    }
    return -1;
}

char *read_env_line(char **env, char *name, int line)
{
    char *value = malloc(sizeof(char) * my_strlen(env[line]));
    int i = 0;
    int x = 0;

    for (x ; env[line][x] != '=' && env[line][x] != '\0' ; x++);
    x++;
    for (x ; env[line][x] != '\0' ; x++) {
        value[i] = env[line][x];
        i++;
    }
    value[i] = '\0';
    return value;
}

char *env_name_cat(char **env, char *name, char *value)
{
    int len = 0;
    char *str;

    if (value == NULL) {
        len = my_strlen(name) + 2;
        str = malloc(sizeof(char) * len);
        str = my_strcat(name, "=");
        return str;
    } else {
        len = my_strlen(name) + my_strlen(value) + 2;
        str = malloc(sizeof(char) * len);
        str = my_strcat(name, "=");
        str = my_strcat(str, value);
        return str;
    }
}