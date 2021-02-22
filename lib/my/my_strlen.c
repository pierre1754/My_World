/*
** EPITECH PROJECT, 2020
** libmy.c
** File description:
** 06/10/2020
*/

int my_strlen(char const *str)
{
    int size_tab = 0;

    for (; str[size_tab] != '\0'; size_tab++);
    return size_tab;
}
