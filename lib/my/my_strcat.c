/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** 06/10/2020
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    int j = 0;

    for (; src[j] != '\0'; j++)
        dest[i + j] = src[j];
    dest[i + j + 1] = '\0';
    return dest;
}
