/*
** EPITECH PROJECT, 2020
** my_compute_power_rec.c
** File description:
** 02/10/2020
*/

static int my_square_root(int nb, double incr_square)
{
    if (incr_square < 46342) {
        if (nb == incr_square)
            return 0;
        if (nb / incr_square == incr_square)
            return incr_square;
        else
            my_square_root(nb, incr_square + 1);
    }
    return 0;
}

int my_compute_square_root(int nb)
{
    double incr_square = 1;

    if (nb < 0)
        return 0;
    if (nb == 1)
        return 1;
    return my_square_root(nb, incr_square);
}
