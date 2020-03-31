/*
** EPITECH PROJECT, 2019
** # my_puterror.c
** File description:
** {description}
*/

#include <unistd.h>

void my_putchar_er(char c)
{
    write(2, &c, 1);
}

int my_puterror(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        my_putchar_er(str[i]);
        i++;
    }
    return (0);
}