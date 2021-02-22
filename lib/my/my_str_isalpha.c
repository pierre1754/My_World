/*
** EPITECH PROJECT, 2020
** my_str_isalpha.c
** File description:
** 02/10/2020
*/

int my_str_isalpha(char const *str)
{
    for (int adv = 0; str[adv] != '\0'; adv++) {
        if ((str[adv] < 'a' || str[adv] > 'z') &&
        (str[adv] < 'A' || str[adv] > 'Z'))
            return 0;
    }
    return 1;
}
