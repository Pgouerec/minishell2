/*
** EPITECH PROJECT, 2019
** # args.c
** File description:
** {description}
*/

#include "my.h"
#include "minishell2.h"

char **str_to_arg_array(char *input)
{
    char **out = malloc(sizeof(char *) * (count_arg(input) + 1));
    char *tmp;
    int c = 0;
    int f = 0;
    int p = 0;
    int size = my_strlen(input);

    for (int x = 0 ; x < size ; x = c + 1) {
        for (c = x ; input[c] != ' ' && input[c] != '\0' ; c++);
        tmp = malloc(sizeof(char) * (c - x + 3));
        f = 0;
        for (c = x ; input[c] != ' ' && input[c] != '\0' ; c++) {
            tmp[f] = input[c];
            f++;
            tmp[f] = '\0';
        }
        out[p] = my_strdup(tmp);
        free(tmp);
        p++;
    }
    out[p] = NULL;
    return out;
}