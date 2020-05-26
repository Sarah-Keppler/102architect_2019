/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** Get the first number from a str. Not from me.
*/

#include <stdio.h>
#include "my.h"

int my_char_isnum(char c)
{
  return ((c >= '0' && c <= '9') ? 1 : 0);
}

long my_parse_nbr(char const *str, long nbr)
{
    int delta_char_to_num = 48;
    long limit = 2147483647;

    while (*str && my_char_isnum(*str)) {
        nbr = nbr * 10 + (*str - delta_char_to_num);
        if (limit < nbr)
            break;
        ++str;
    }
    return (nbr);
}

int my_getnbr(char const *str)
{
    long nbr = 0;
    int n_minuses = 0;
    long limit = 2147483647;

    while (*str && !(nbr)) {
        if (*str == '-') {
            ++n_minuses;
        } else if (my_char_isnum(*str)) {
            nbr = my_parse_nbr(str, nbr);
        }
        if (nbr > limit) {
            return (0);
        }
        str++;
    }
    n_minuses = (n_minuses % 2) ? (- 1) : (1);
    nbr *= n_minuses;
    return (nbr);
}
