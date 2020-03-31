/*
** EPITECH PROJECT, 2019
** # printsh.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell.h"

void printsh_advanced(char **env)
{
    char *host = get_env_value(env, "HOSTNAME");
    char *pwdall = get_env_value(env, "PWD");
    char *user = get_env_value(env, "USER");
    char *home = get_env_value(env, "HOME");
    char *pwd;

    if (user == NULL)
        user = "username";
    if (host == NULL)
        host = "localhost";
    if (pwdall == NULL)
        pwdall = get_current_folder();
    else if (my_strcmp(pwd_parse(pwdall), pwd_parse(home)) == 1)
        pwd = pwd_parse(pwdall);
    else
        pwd = "~";
    my_printf("\e[1m\e[32m[%s@%s ", user, host);
    my_printf("\e[39m%s\e[32m]$ \e[39m\e[0m", pwd);
}

void printsh(char **env)
{
    my_printf("$> ");
}

char *pwd_parse(char *pwd)
{
    int len = my_strlen(pwd);
    int x;
    int i = 0;
    char *parsed;

    for (x = len ; pwd[x] != '/' ; x--);
    parsed = malloc(sizeof(char) * len - x + 1);
    x++;
    for (x ; pwd[x] != '\0' ; x++) {
        parsed[i] = pwd[x];
        i++;
    }
    return parsed;
}