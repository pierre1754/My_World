/*
** EPITECH PROJECT, 2020
** my_strncmp.c
** File description:
** 06/10/2020
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (i = 0; i < n && s1[i] && s2[i]; i++)
        if (s1[i] != s2[i])
            break;
    return s1[i] - s2[i];
}
