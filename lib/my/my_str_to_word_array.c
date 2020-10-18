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
    char **output = malloc(sizeof(char *) * (count_word(str) + 1));
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
            tmp[f] = '\0';
        }
        output[p] = tmp;
        p++;
    }
    output[p] = NULL;
    return (output);
}

int count_word(char *str)
{
    int nb_of_word = 0;

    for (int x = 0 ; str[x] != '\0' ; x++) {
        if (str[x] == ' ')
            nb_of_word++;
    }
    nb_of_word++;
    return nb_of_word;
}