/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** Return smallest prime number that is gt than or eq to the given number.
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int res = nb;

    while (my_is_prime(res) != 1)
    {
        res++;
    }
    return (res);
}