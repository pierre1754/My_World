/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** 08/10/2020
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char **strdup_2d(char **array)
{
    int len = 0;
    char **res = NULL;

    for (; array[len]; len++);
    res = init_array(len);
    for (int i = 0; res[i]; i++) {
        res[i] = my_strdup(array[i]);
    }
    return res;
}
