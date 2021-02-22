/*
** EPITECH PROJECT, 2020
** my_find_prime_sup.c
** File description:
** 02/10/2020
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    for (nb; 1; nb++)
        if (my_is_prime(nb) != 0)
            return nb;
    return 0;
}
