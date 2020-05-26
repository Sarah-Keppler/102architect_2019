/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** Copy a string until n position.
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != src[n]) {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return (dest);
}
