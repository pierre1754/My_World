/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void init_map(void)
{
    engine_t *engine = get_engine();

    init_map_int(GET_MAP_3D(engine));
    init_map_int(GET_MAP_3D_BASE(engine));
    calc_map_vec(GET_MAP_2D(engine), GET_MAP_3D(engine));
    calc_map_vec(GET_MAP_2D_BASE(engine), GET_MAP_3D_BASE(engine));
    init_map_ver(GET_MAP_VER(engine), GET_MAP_2D(engine));
    init_map_ver(GET_MAP_ORIGIN(engine), GET_MAP_2D_BASE(engine));
    init_map_line();
}

void init_map_perl(int **map)
{
    engine_t *engine = get_engine();

    if (GET_SET_LOD(engine)) {
        GET_SET_LOD(engine) = 0;
        return;
    }
    for (int i = 0; i < GET_SET_MX(engine); i++) {
        for (int j = 0; j <= GET_SET_MY(engine); j++) {
            map[i][j] = 0 /* 50 * perlin2d(i, j, 0.02, 4) */;
        }
    }
    map[GET_SET_MX(engine)] = NULL;
}
