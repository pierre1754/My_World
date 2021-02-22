/*
** EPITECH PROJECT, 2020
** my_compute_power_rec.c
** File description:
** 02/10/2020
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    if (p > 0)
        return (nb * my_compute_power_rec(nb, p - 1));
    else if (p < 0)
        return 0;
    else
        return 1;
}
