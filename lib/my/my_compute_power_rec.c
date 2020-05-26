/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** Take a int. Power it. Return it.
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    if (0 > p)
        return (0);
    if (0 == p)
        return (1);
    if (1 < p) {
        nb *= my_compute_power_rec(nb, p - 1);
        return (nb);
    }
    return (nb);
}
