/*
** EPITECH PROJECT, 2019
** my_str_isfloat
** File description:
** Return 1 if a str contains a float.
*/

#include "my.h"

int my_str_isint_float(char const *str)
{
    int point = 0;
    int neg = 0;

    if (1 == my_strlen(str) && (str[0] == '.' || str[0] == '-'))
        return (0);
    while ('\0' != *str) {
        if (!('0' <= *str && '9' >= *str) && '-' != *str && '.' != *str)
            return (0);
        if ('.' == *str)
            ++point;
        if ('-' == *str)
            ++neg;
        ++str;
    }
    if (1 < neg || 1 < point)
        return (0);
    return (1);
}
