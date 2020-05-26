/*
** EPITECH PROJECT, 2019
** my_swap_char
** File description:
** Swap two chars.
*/

#include "my.h"

void my_swap_char(char *start, char *end)
{
    char save = *end;

    *end = *start;
    *start = save;
}
