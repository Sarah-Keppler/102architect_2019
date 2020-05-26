/*
** EPITECH PROJECT, 2019
** check_errors
** File description:
** Return 1 if an erro occurs. For 101pong.
*/

#include <stdio.h>
#include "my.h"

int check_errors(int ac, char **av)
{
    if (ac != 8) {
        printf("Error 1.1");
        return (84);
    }
    for (int i = 1; ac > i; ++i) {
	for (int y = 0; '\0' != av[i][y]; ++y)
            if (!('0' <= av[i][y] && '9' >= av[i][y]) && '.' != av[i][y] && '-' != av[i][y]) {
                printf("Error 2.1");
		return (84);
            }
	if (1 < nb_of_the_char_given(av[i], '.') || (1 < nb_of_the_char_given(av[i], '-'))) {
            printf("Error 2.2");
            return (84);
        }
    }
    for (int j = 0; my_strlen(av[7]) > j; ++j) {
        if ('.' == av[7][j]) {
            printf("Error 3.1");
            return (84);
        }
        else if ('-' == av[7][j]) {
            printf("Error 3.2");
            return (84);
        }
    }
    return (1);
}
