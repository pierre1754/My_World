/*
** EPITECH PROJECT, 2020
** my_strstr.c
** File description:
** 05/10/2020
*/

#include <stdio.h>

char *my_strstr(char *str, char const *to_find)
{
    int match_time = 0;

    if (!to_find[0])
        return str;
    if (!str[0])
        return 0;
    for (int adv = 0; str[adv] != '\0'; adv++) {
        if (str[adv] == to_find[0])
            match_time = adv;
        for (int match = 0; str[adv + match] == to_find[match]; match++) {
            if (to_find[match + 1] == '\0')
                return (str + match_time);
            if ((str[adv + match + 1] == '\0') && (to_find[match + 1] != 0))
                return 0;
        }
    }
    return 0;
}
