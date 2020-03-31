/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** ...
*/

int my_strlen(char const *src);

int my_str_isnum(char const *str)
{
    int str_len = my_strlen(str);
    int str_len_diff = 0;
    int i = 0;

    for (i ; str[i] != '\0' ; i++) {
        if (str[i] < 58 && str[i] > 46)
            str_len_diff++;
    }

    if (str_len != str_len_diff)
        return (0);
    else
        return (1);
}