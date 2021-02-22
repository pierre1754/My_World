/*
** EPITECH PROJECT, 2020
** my_first_wordlen.c
** File description:
** 08/10/2020
*/

#include <stdio.h>

int my_first_wordlen(char const *str)
{
    int r = 0;
    while (!(str[r] == ' ' || str[r] == 44 || str[r] == '.' || str[r] == '\0'))
        r++;
    return r;
}
