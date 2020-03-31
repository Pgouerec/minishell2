/*
** EPITECH PROJECT, 2019
** my_str_str
** File description:
** This is a str str function made by student
*/

#include <stdio.h>

int my_strlen(char const *str);

char *my_strstr(char *str, char const *to_find)
{
    int to_find_len = my_strlen(to_find);
    int i;
    int diff;
    int word;

    for (i = 0; str[i] != '\0'; i++) {
        diff = i;
        for (word = 0; str[i] == to_find[word]; word++) {
            i++;
            if (to_find[i] == '\0')
                return (&str[diff]);
        }
    }
    return (0);
}