/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** Function return first argument raised by the power of second argument.
*/

int my_compute_power_rec(int nb, int p)
{
    int x;

    if (p == 1)
        return (nb);
    for (;p > 1; p--) {
        nb = nb * nb;
    }
    return (nb);
}