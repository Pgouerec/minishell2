/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Displaying all number given as parameter.
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int high_nb;

    if (nb < 0) {
        my_putchar(45);
        nb -= nb;
    }
    if (nb < 10) {
        my_putchar(48+nb);
    }
    if (nb >= 10) {
        my_put_nbr(nb/10);
        my_putchar(48 + nb%10);
    }
    return (0);
}