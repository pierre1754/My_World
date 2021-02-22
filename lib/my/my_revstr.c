/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** 05/10/2020
*/

#include "my.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str) - 1;
    char temp;

    for (int i = 0; i < (len + 1) / 2; i++, len--) {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
    }
    return (str);
}
