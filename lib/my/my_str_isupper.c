/*
** EPITECH PROJECT, 2020
** my_sort_isupper.c
** File description:
** 07/10/2020
*/

int my_str_isupper(char const *str)
{
    for (int adv = 0; str[adv] != '\0'; adv++)
        if (str[adv] < 'A' || str[adv] > 'Z')
            return 0;
    return 1;
}
