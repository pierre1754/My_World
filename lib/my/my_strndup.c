/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** 08/10/2020
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char *my_strndup(char const *src, int n)
{
    char *cp_src = malloc(sizeof(char) * (n + 1));
    int i = 0;

    for (; src[i] && i < n; i++)
        cp_src[i] = src[i];
    cp_src[i] = '\0';
    return cp_src;
}
