/*
** EPITECH PROJECT, 2020
** my_swap.c
** File description:
** 01/10/2020
*/

void my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
