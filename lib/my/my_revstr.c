/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** Return a reverse string.
*/

#include "my.h"

char *my_revstr(char *str)
{
    char *end = str + my_strlen(str) - 1;
    char *start = str;

    while (start < end) {
        my_swap_char(start, end);
        --end;
        ++start;
    }
    return (str);
}
