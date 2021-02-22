/*
** EPITECH PROJECT, 2020
** my_square_root.c
** File description:
** 08/10/2020
*/

int my_square_root(int nb, double incr_squareroot)
{
    if (incr_squareroot < 46342) {
        if (nb / incr_squareroot == incr_squareroot)
            return incr_squareroot;
        else
            my_square_root(nb, incr_squareroot + 1);
        if (nb == incr_squareroot)
            return 0;
    }
    return 0;
}
