/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Return numbers sent as string.
*/

void my_putchar(char c);

int my_strlen(char const *str);

int my_getnbr(char const *str)
{
    int result = 0;
    int sign = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - 48);
            if (str[i - 1] == '-')
                sign = - 1;
            if (str[i + 1] > '9' || str[i + 1] < '0') {
                result *= sign;
                return (result);
            }
        }
    }
    return (0);
}