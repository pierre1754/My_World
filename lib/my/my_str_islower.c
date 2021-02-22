/*
** EPITECH PROJECT, 2020
** my_str_islower.c
** File description:
** 02/10/2020
*/

int my_str_islower(char const *str)
{
    for (int adv = 0; str[adv] != '\0'; adv++)
        if (str[adv] < 'a' || str[adv] > 'z')
            return 0;
    return 1;
}
