/*
** EPITECH PROJECT, 2020
** my_find_prime_sup.c
** File description:
** 02/10/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char **init_array(int y)
{
    char **array = malloc(sizeof(char *) * (y + 1));

    if (!array)
        return NULL;
    for (int i = 0; i < y; i++) {
        array[i] = "0";
    }
    array[y] = NULL;
    return array;
}
