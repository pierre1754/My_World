/*
** EPITECH PROJECT, 2020
** my_strcpy.c
** File description:
** 05/10/2020
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    if (i == 0)
        dest[0] = '\0';
    return (dest);
}
