/*
** EPITECH PROJECT, 2020
** my_strcapitalize.c
** File description:
** 06/10/2020
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    int cond_dif_high;
    int cond_dif_low;
    int cond_dif_digits;

    my_strlowcase(str);
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;
    for (int i = 1; str[i] != '\0'; i++) {
        cond_dif_high = (str[i - 1] < 'A' || str[i - 1] > 'Z');
        cond_dif_low = (str[i - 1] < 'a' || str[i - 1] > 'z');
        cond_dif_digits = (str[i - 1] < '0' || str[i - 1] > '9');
        if (cond_dif_low && cond_dif_high && cond_dif_digits)
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] -= 32;
    }
    return (str);
}
