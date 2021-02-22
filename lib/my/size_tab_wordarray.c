/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** 08/10/2020
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int size_tab_wordarray(char const *str)
{
    int result = 0;
    int cond_digits = 0;
    int cond_lower = 0;
    int cond_higher = 0;

    for (int i = 0; str[i]; i++) {
        cond_digits = ((str[i - 1] > 47 && str[i - 1] < 58));
        cond_lower = ((str[i - 1] > 96 && str[i - 1] < 123));
        cond_higher = ((str[i - 1] > 64 && str[i - 1] < 91));
        if (str[i] == ' ' &&  (cond_digits || cond_lower || cond_higher))
            result++;
    }
    result += 2;
    return result;
}
