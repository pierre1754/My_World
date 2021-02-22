/*
** EPITECH PROJECT, 2020
** libmy.c
** File description:
** 06/10/2020
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
