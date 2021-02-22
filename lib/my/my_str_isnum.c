/*
** EPITECH PROJECT, 2020
** my_str_islower.c
** File description:
** 02/10/2020
*/

int my_str_isnum(char const *str)
{
    for (int adv = 0; str[adv] != '\0'; adv++)
        if (str[adv] < '0' || str[adv] > '9')
            return 0;
    return 1;
}
