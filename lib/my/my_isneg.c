/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** Display N if negative, P is positive or Null.
*/

char my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar(78);
    } else if (n >= 0) {
        my_putchar(80);
    }
    my_putchar('\n');
}