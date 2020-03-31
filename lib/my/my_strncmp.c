/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** Compares file whit specified number of char.
*/

int my_strncmp(char const *s1, char *s2, int n)
{
    int ascii_s1 = 0;
    int ascii_diff = 0;
    int ascii_result = 0;

    for (int i = 0; i < n; i++) {
        if (s1[i] != '\0') {
            ascii_s1 += s1[i];
            if (s1[i] != s2[i])
                ascii_diff += s2[i];
        }
    }
    ascii_result = ascii_s1 - ascii_diff;
    if (ascii_result == 0) {
        return (0);
    } else {
        return (ascii_result);
    }
}