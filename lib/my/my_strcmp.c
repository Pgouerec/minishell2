/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** Compare to string.
*/

int my_strcmp(char const *s1, char const *s2)
{
    int x = 0;

    for (x ; s1[x] != '\0' && s2[x] != '\0' ; x++) {
        if (s1[x] != s2[x])
            return 1;
    }
    return 0;
}