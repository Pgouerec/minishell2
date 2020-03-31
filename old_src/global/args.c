/*
** EPITECH PROJECT, 2019
** # args.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell.h"

char **parse_args(char *av)
{
    char **parsed;
    int i = 0;
    int size = 0;
    int wordsz = 0;
    char **args = my_str_to_arg_array(av);

    for (size ; args[size] != NULL ; size++);
    parsed = malloc(sizeof(char *) * size);
    for (int x = 0 ; args[x] != NULL ; x++) {
        for (wordsz ; args[x][wordsz] != '\0' ; wordsz++);
        parsed[i] = malloc(sizeof(char) * wordsz + 1);
        parsed[i] = args[x];
        wordsz = 0;
        i++;
    }
    return parsed;
}

char **my_str_to_arg_array(char *str)
{
    char **output = malloc(sizeof(char *) * 50);
    char *tmp;
    int c = 0;
    int f = 0;
    int p = 0;
    int size = my_strlen(str);

    for (int x = 0 ; x < size ; x = c + 1) {
        for (c = x ; str[c] != ' ' && str[c] != '\t' &&
            str[c] != '\n' && str[c] != '\0' ; c++);
        tmp = malloc(sizeof(char) * c -x + 1);
        f = 0;
        for (c = x ; str[c] != ' ' && str[c] != '\t' &&
            str[c] != '\n' && str[c] != '\0' ; c++) {
            tmp[f] = str[c];
            f++;
        }
        my_printf("%s\n", tmp);
        output[p] = tmp;
        p++;
    }
    return (output);
}