/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** Compare two strings.
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int number = 0;

    while ('\0' != s1[number] || '\0' != s2[number]) {
        if (s1[number] > s2[number])
            return (1);
        if (s1[number] < s2[number])
            return (-1);
        ++number;
        if ('\0' == s1[number] && '\0' == s2[number])
            return (0);
    }
    if ('\0' == s1[number])
        return (-1);
    else
        return (1);
}
