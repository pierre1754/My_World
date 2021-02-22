/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** 08/10/2020
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = 0;
    char *cp_src = malloc(sizeof(char) * (my_strlen(src) + 1));

    for (; src[i]; i++)
        cp_src[i] = src[i];
    cp_src[i] = '\0';
    return cp_src;
}
