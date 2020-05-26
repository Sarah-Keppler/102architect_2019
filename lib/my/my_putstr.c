/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Display a string.
*/

#include "my.h"

int my_putstr(char const *str)
{
    while ('\0' != *str) {
        my_putchar(*str);
        ++str;
    }
}
