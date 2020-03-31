/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** Reverse all character of string.
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int str_len;
    int i;
    char a;

    str_len = my_strlen(str) - 1;
    for (i = 0; str_len/2 >= i; i++)
        {
        if (str_len - i != i) {
            a = str[i];
            str[i] = str[str_len - i];
            str[str_len - i] = a;
            }
        }
    return (str);
}