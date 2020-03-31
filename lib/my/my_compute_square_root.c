/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** Return the square root of the given number.
*/

int my_compute_square_root(int nb)
{
    int y;

    if (nb < 0)
        return (0);
    for (y = 0; y * y != nb; y++)
    {
        if (y > nb)
            return (0);
    }
    return (y);
}