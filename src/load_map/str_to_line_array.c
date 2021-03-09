/*
** EPITECH PROJECT, 2020
** my_skoban
** File description:
** read_arg
*/

#include "my_world.h"

char **init_array(int y)
{
    char **array = malloc(sizeof(char *) * (y + 1));

    if (!array)
        return NULL;
    for (int i = 0; i < y; i++) {
        array[i] = "0";
    }
    array[y] = NULL;
    return array;
}

char **my_str_to_line_array(char const *file)
{
    int y = 0;
    int x = 0;
    char **map = NULL;

    for (int i = 0; file[i]; i++)
        if (file[i] == '\n')
            y++;
    map = init_array(y);
    if (!map)
        return NULL;
    for (int nb_arr = 0; map[nb_arr]; nb_arr++) {
        for (x = 0; file[x] != '\n'; x++);
        map[nb_arr] = my_strndup(file, x);
        file += x + 1;
    }
    return map;
}
