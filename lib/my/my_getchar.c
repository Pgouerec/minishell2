/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Return numbers sent as string.
*/

#include <stdlib.h>

void my_putchar(char);

int my_strlen(char const *str);

char *my_getchar(char const *str)
{
    int len = my_strlen(str);
    char *result = malloc(sizeof(char) * len);
    int i = 0;

    if (str[i] == '-'){
        i = 1;
        for (i ; str[i] != '\0' ; i++) {
            result[i - 1] = str[i];
        }
        result[i] = '\0';
    } else {
        for (i ; str[i] != '\0' ; i++)
            result[i] = str[i];
        result[i] = '\0';
        return (result);
    }
    return (result);
}