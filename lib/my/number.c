/*
** EPITECH PROJECT, 2019
** number
** File description:
** Return how many times an arg appears.
*/

#include "my.h"

int nb_of_the_char_given(char *src, char c)
{
    int count = 0;

    for (int i = 0; '\0' != src[i]; ++i)
        if (c == src[i])
            ++count;
    return (count);
}

int nb_of_digits(int nb)
{
    int count = 0;
    int figure = 0;

    while (nb != 0) {
        figure = nb % 10;
        nb /= 10;
        ++count;
    }
    return (count);
}
