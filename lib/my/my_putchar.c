/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** Display a char.
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
