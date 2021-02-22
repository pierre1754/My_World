/*
** EPITECH PROJECT, 2020
** my_strncpy.c
** File description:
** 05/10/2020
*/

#include <stdio.h>
#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    if (n < 0)
        return 0;
    for (int adv = 0; adv < n && src[adv]; adv++) {
        if (dest[adv] == 0)
            dest[my_strlen(src)] = 0;
        dest[adv] = src[adv];
    }
    return (dest);
}
