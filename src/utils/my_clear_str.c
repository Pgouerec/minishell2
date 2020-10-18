/*
** EPITECH PROJECT, 2019
** # my_clear_str.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

char *my_clear_str(char *str)
{
    char tmp[256];
    char *new;
    int n = 0;

    badchar_to_space(str);
    for (int y = 0 ; str[y] != '\0' && str[y] != '\n' ; y++) {
        if (str[y] != ' ') {
            tmp[n] = str[y];
            n++;
        } else if (str[y] == ' ' && str[y + 1] != ' ' &&
                    str[y + 1] != '\0' && n != 0) {
            tmp[n] = ' ';
            n++;
        }
    }
    tmp[n] = '\0';
    new = my_strdup(tmp);
    return (if_empty(new));
}

char *if_empty(char *str)
{
    for (int x = 0 ; str[x] != '\0' ; x++) {
        if (str[x] != ' ')
            return str;
    }
    free(str);
    return NULL;
}

char *badchar_to_space(char *str)
{
    for (int x = 0 ; str[x] != '\0' ; x++) {
        if (is_notprintable_char(str[x]) != 0)
            str[x] = ' ';
    }
    return (str);
}

int is_notprintable_char(char c)
{
    if (c > 126 || (c < 32 && c != '\0'))
        return (-1);
    else
        return (0);
}