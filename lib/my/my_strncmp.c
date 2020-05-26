/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** Compare until n position in a string.
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int number = 0;

    while (s1[number] != s1[n]) {
        if (s1[number] > s2[number])
            return (1);
        if (s1[number] < s2[number])
            return (-1);
        ++number;
    }
    return (0);
}
