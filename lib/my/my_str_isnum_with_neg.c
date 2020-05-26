/*
** EPITECH PROJECT, 2019
** my_str_isnum_with_neg
** File description:
** Return 1 if a str contains numbers and - signs.
*/

#include "my.h"

int my_str_isnum_with_neg(char const *str)
{
    while ('\0' != *str) {
        if (!('0' <= *str && '9' >= *str) && '-' != *str)
            return (0);
        ++str;
    }
    return (1);
}
