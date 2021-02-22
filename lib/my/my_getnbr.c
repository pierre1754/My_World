/*
** EPITECH PROJECT, 2020
** my_getnbr_advanced.c
** File description:
** 01/10/2020
*/

#include <stdio.h>

static int lim_size(long int result)
{
    if (result >= -2147483648 && result <= 2147483647)
        return result;
    return 0;
}

int my_getnbr(char const *str)
{
    long int result = 0;
    int nbr = 0;
    int power = 1;
    int digits = str[0] == '+' || str[0] == '-';
    int adv = 0;
    int m = 0;

    for (; str[m] == '+' || str[m] == '-'; m++ )
        if (str[m] == '-')
            adv++;
    digits = ((str[m] >= '0') && (str[m] <= '9'));
    for (int i = m; ((str[i] >= '0') && (str[i] <= '9')); i++, nbr++);
    for (; nbr > 0; nbr--) {
        result += (str[m + nbr - 1] - '0') * power;
        lim_size(result);
        power *= 10;
    }
    if (adv % 2 != 0)
        result *= -1;
    return lim_size(result);
}
