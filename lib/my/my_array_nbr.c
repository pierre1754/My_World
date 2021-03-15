/*
** EPITECH PROJECT, 2020
** my_find_prime_sup.c
** File description:
** 02/10/2020
*/

#include "my.h"

char *my_array_nbr(int nb, int size, char *buffer)
{
    int comm = 0;

    memset(buffer, '0', size - 1);
    buffer[size] = '\0';
    if (buffer) {
        for (int i = 0; nb && size; i++, size--) {
            comm = nb % 10;
            nb = nb / 10;
            buffer[size - 1] = comm + '0';
        }
    }
    for (; *buffer == '0' && *buffer; buffer++);
    if (*buffer == '\0') {
        buffer--;
    }
    return buffer;
}
