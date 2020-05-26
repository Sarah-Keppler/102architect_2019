/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** Swap two ints.
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int save = *b;

    *b = *a;
    *a = save;
}
