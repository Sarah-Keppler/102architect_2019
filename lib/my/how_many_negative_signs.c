/*
** EPITECH PROJECT, 2019
** how_many
** File description:
** Return the number of negative signs.
*/

#include <unistd.h>
#include "my.h"
#include "infin.h"

int how_many_negative_signs(char *str)
{
    int number = 0;
    char *strcpy = str;

    while ('\0' != *str) {
        if ('-' == *str)
            ++number;
        ++str;
    }
    if (strcpy[0] != '-' && number >= 1)
        return (number);
    return (number);
}
