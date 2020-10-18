/*
** EPITECH PROJECT, 2019
** # to_array.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

char **env_to_array(minishell_t *sh)
{
    env_line_t *env = sh->env.first;
    int length = list_length(sh);
    char **env_array = malloc(sizeof(char *) * (length + 1));
    char *tmp = NULL;
    int n = 0;

    while (env) {
        tmp = my_strdup(env->name);
        tmp = my_realloc(tmp, (my_strlen(env->value) + 2));
        tmp = my_cat(tmp, "=");
        tmp = my_cat(tmp, env->value);
        env_array[n] = tmp;
        n++;
        env = env->next;
    }
    env_array[n] = NULL;
    return (env_array);
}

int list_length(minishell_t *sh)
{
    env_line_t *env = sh->env.first;
    int length = 0;

    while (env) {
        length++;
        env = env->next;
    }
    length++;
    return (length);
}