/*
** EPITECH PROJECT, 2019
** # is_alphanum.c
** File description:
** {description}
*/

int my_strlen(char const *src);

int is_alphanum(char const *str)
{
    int str_len = my_strlen(str);
    int str_len_diff = 0;
    int i = 0;

    for (i ; str[i] != '\0' ; i++) {
        if (str[i] < 123 && str[i] > 96)
            str_len_diff++;
        else if (str[i] < 91 && str[i] > 64)
            str_len_diff++;
        else if (str[i] < 58 && str[i] > 46)
            str_len_diff++;
    }

    if (str_len != str_len_diff)
        return (0);
    else
        return (1);
}