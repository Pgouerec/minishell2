/*
** EPITECH PROJECT, 2019
** # my_str_to_word_array.c
** File description:
** {description}
*/

#include "my.h"
#include <stdlib.h>

char **my_str_to_word_array(char *str)
{
    char **output = malloc(sizeof(char *) * 50);
    char *tmp;
    int c = 0;
    int f = 0;
    int p = 0;
    int size = my_strlen(str);

    for (int x = 0 ; x < size ; x = c + 1) {
        for (c = x ; str[c] != ' ' && str[c] != '\0' ; c++);
        tmp = malloc(sizeof(char) * c -x + 1);
        f = 0;
        for (c = x ; str[c] != ' ' && str[c] != '\0' ; c++) {
            tmp[f] = str[c];
            f++;
        }
        output[p] = tmp;
        p++;
    }
    return (output);
}