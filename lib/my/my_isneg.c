/*
** EPITECH PROJECT, 2020
** libmy.c
** File description:
** 06/10/2020
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return 0;
}
