/*
** EPITECH PROJECT, 2020
** my_str_isprintable.c
** File description:
** 02/10/2020
*/

int my_str_isprintable(char const *str)
{
    for (int adv = 0; str[adv] != '\0'; adv++)
        if (str[adv] < ' ' || str[adv] > '~')
            return 0;
    return 1;
}
