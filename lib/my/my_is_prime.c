/*
** EPITECH PROJECT, 2020
** my_is_prime.c
** File description:
** 02/10/2020
*/

int my_is_prime(int nb)
{
    double scan = nb;
    int factor = 0;

    if (nb < 2)
        return 0;
    for (int i = 1; i <= nb; i++)
        if ((scan / i) == (nb / i))
            factor++;
    if (factor > 2)
        return 0;
    return 1;
}
