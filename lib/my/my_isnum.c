/*
** EPITECH PROJECT, 2020
** my_isnum.c
** File description:
** 02/10/2020
*/

int my_isnum(char const *str)
{
    int lower = 0;
    int upper = 0;
    int nbr = 0;

    for (int adv = 0; str[adv] != '\0'; adv++) {
        lower = (str[adv] < 'a' || str[adv] > 'z');
        upper = (str[adv] < 'A' || str[adv] > 'Z');
        nbr = (str[adv] < '0' || str[adv] > '9');
        if (lower && upper && nbr)
            return 0;
    }
    return 1;
}
