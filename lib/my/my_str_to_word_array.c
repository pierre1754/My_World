/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** 08/10/2020
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

static char **init_array(char const *str)
{
    char **ar_two_dimension = malloc(sizeof(char *) * size_tab_wordarray(str));

    for (int i = 0; i < size_tab_wordarray(str); i++)
        ar_two_dimension[i] = NULL;
    return ar_two_dimension;
}

char **my_str_to_word_array(char const *str)
{
    if (str == 0)
        return 0;
    char **array_two_dimension = init_array(str);
    int word_size = 0;
    int adv = 0;

    for (int first_tab = 0; first_tab < size_tab_wordarray(str); first_tab++) {
        while (((str[adv] >= 'A' && str[adv] <= 'Z') ||
        (str[adv] >= 'a' && str[adv] <= 'z')))
            adv++;
        if (str[adv] == '\0')
            return array_two_dimension;
        word_size = my_first_wordlen(str + adv);
        array_two_dimension[first_tab] = malloc(sizeof(char) * (word_size + 1));
        my_strncpy(array_two_dimension[first_tab], (str + adv), word_size);
        adv += word_size;
    }
    array_two_dimension[size_tab_wordarray(str) - 1] = NULL;
    return array_two_dimension;
}
