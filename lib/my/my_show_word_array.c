/*
** EPITECH PROJECT, 2020
** my_show_word_array.c
** File description:
** 08/10/2020
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i]; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return 0;
}
