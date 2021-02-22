/*
** EPITECH PROJECT, 2020
** my_find_prime_sup.c
** File description:
** 02/10/2020
*/

#include <stdio.h>
#include "my.h"

void my_array_nbr(int nb, char *array, int array_size)
{
    int dec;
    int comm;

    if (array) {
        comm = nb % 10;
        dec = nb / 10;
        if (dec != 0)
            my_array_nbr(dec, array, array_size - 1);
        array[array_size] = comm + '0';
    }
}
