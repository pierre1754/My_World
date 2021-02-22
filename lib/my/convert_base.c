/*
** EPITECH PROJECT, 2020
** my_compute_power_rec.c
** File description:
** 02/10/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static char *convert_dec(int res, int size_to, char const *base_to, char *array)
{
    int modul = 0;
    int f = 0;

    for (f = 0; res > 0; f++) {
        modul = res % size_to;
        array[f] = base_to[modul];
        res /= size_to;
    }
    array[f] = 0;
    return array;
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    int size_from = my_strlen(base_from);
    int size_to = my_strlen(base_to);
    int size_nbr = my_strlen(nbr) - 1;
    char *array = malloc(sizeof(char) * (my_strlen(nbr) * 4));
    int res = 0;
    int i = 0;

    for (int digit = 0; nbr[digit]; digit++) {
        for (i = 0; nbr[digit] != base_from[i]; i++);
        res += i * my_compute_power_rec(size_from, size_nbr);
        size_nbr--;
    }
    return my_revstr(convert_dec(res, size_to, base_to, array));
}
