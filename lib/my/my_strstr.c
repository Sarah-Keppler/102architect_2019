/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** Find a string in a string. Return it.
*/

#include <stdlib.h>
#include "my.h"

int match(char *str, char const *to_find, int i)
{
    int number = 0;
    int g = 0;

    while (to_find[g] == str[i] && '\0' != str[i]) {
        ++number;
        ++g;
        ++i;
    }
    if (number == my_strlen(to_find))
        return(1);
    return (0);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == to_find[0])
            if (match(str, to_find, i))
                return (str + i);
        ++i;
    }
    return (NULL);
}
