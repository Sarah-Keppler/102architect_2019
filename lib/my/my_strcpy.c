/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** Copy a string already malloc.
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while ('\0' != src[i]) {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return (dest);
}
