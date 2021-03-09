/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void calc_map_vec(sfVector2f **map, int **map_int)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        for (int j = 0; j < GET_SET_MY(engine); j++)
            map[i][j] = set_iso_point(i, j, map_int[i][j]);
    }
}
