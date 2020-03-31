/*
** EPITECH PROJECT, 2019
** # my_strncat.c
** File description:
** {description}
*/

int my_strlen(char const *src);

char *my_strcat(char *dest, char const *src, int nb)
{
    int i = my_strlen(dest);
    int x = 0;

    for (x; x < nb && src[x] != '\0'; x++) {
        dest[i + x] = src[x];
        i++;
    }
    dest[i + x] = src[x + 1];
    return (dest);
}