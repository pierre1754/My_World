/*
** EPITECH PROJECT, 2020
** my_strncat.c
** File description:
** 06/10/2020
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    for (; dest[i] != '\0'; i++);
    for (; j < nb; j++)
        dest[i + j] = src[j];
    dest[i + j + 1] = '\0';
    return dest;
}
