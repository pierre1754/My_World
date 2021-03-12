/*
** EPITECH PROJECT, 2020
** my_find_prime_sup.c
** File description:
** 02/10/2020
*/

#include "my.h"

char *my_array_nbr(int nb, int size)
{
    char *result = malloc(sizeof(char) * size + 1);
    int comm = 0;

    memset(result, '0', size);
    result[size] = '\0';
    if (result) {
        for (int i = 0; nb && size; i++, size--) {
            comm = nb % 10;
            nb = nb / 10;
            result[size - 1] = comm + '0';
        }
    }
    return result;
}
