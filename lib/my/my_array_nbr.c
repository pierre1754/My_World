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
    int comm = nb % 10;
    int dec = nb / 10;

    memset(result, '0', size);
    result[size] = '\0';
    if (result) {
        for (int i = 0; dec && size; i++, size--) {
            result[size - 1] = comm + '0';
            comm = nb % 10;
            dec = nb / 10;
        }
    }
    return result;
}
