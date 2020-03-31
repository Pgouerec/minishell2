/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** Return 1 if the number is prime and 0 if not.
*/

int my_is_prime(int nb)
{
    int y = 2;

    if (nb == 0 || nb == 1)
        return (0);
    while (y < nb)
    {
        if (nb % y == 0)
            return (0);
        y++;
    }
    return (1);
}