/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** Copy specific char of string into an other.
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i; src[i] != '\0'; i++) {
        if (i == n + 1) {
            dest[i] = '\0';
            return (dest);
        }
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}