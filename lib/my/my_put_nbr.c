/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Displays a number.
*/

#include "my.h"

int display_digits(int nb)
{
    int figure = nb % 10;

    nb = nb / 10;
    if (nb != 0)
        display_digits(nb);
    my_putchar(figure + 48);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        if (nb == -2147483648) {
            nb += 2000000000;
            my_putchar('2');
        }
        display_digits(-nb);
    }
    else
        display_digits(nb);
}
