/*
** EPITECH PROJECT, 2020
** my_skoban
** File description:
** read_arg
*/

#include "my_world.h"

int y_size(char *file)
{
    int y = 0;

    for (int i = 0; file[i] != ';' && file[i]; i++) {
        if (file[i] == ',') {
            y++;
        }
    }
    return y + 1;
}

int x_size(char *file)
{
    int x = 0;

    for (int i = 0; file[i]; i++) {
        if (file[i] == ';') {
            x++;
        }
    }
    return x;
}

void get_size_map(char *file)
{
    engine_t *engine = get_engine();

    GET_SET_MX(engine) = x_size(file);
    GET_SET_MY(engine) = y_size(file);
}

void file_to_map(char **file)
{
    engine_t *engine = get_engine();
    int **result = malloc(sizeof(int *) * (GET_SET_MX(engine) + 1));

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        result[i] = malloc(sizeof(int) * (GET_SET_MY(engine) + 1));
        for (int j = 0; j < GET_SET_MY(engine); j++) {
            result[i][j] = my_getnbr(file[i]);
            for (; *file[i] != ',' && *file[i]; file[i]++);
            file[i]++;
        }
    }
    result[GET_SET_MX(engine)] = NULL;
    GET_MAP_3D(engine) = result;
}
