/*
** EPITECH PROJECT, 2020
** get_on_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

static void set_texture(int i, int j)
{
    engine_t *engine = get_engine();

    if (GET_MAP_3D(engine)[i][j + 1] > GET_MAP_3D(engine)[i + 1][j] ||
    GET_MAP_3D(engine)[i][j + 1] > GET_MAP_3D(engine)[i][j] ||
    GET_MAP_3D(engine)[i][j] > GET_MAP_3D(engine)[i + 1][j]) {
        for (int a = 0; a < 4; a++) {
            sfVertexArray_getVertex(GET_MAP_TEX(engine)[i][j], a)->color =
            sfColor_fromRGBA(200, 200, 200, 255);
        }
    }
}

void set_texture_params(int i, int j)
{
    if (i != 0)
        set_texture(i, j);
}
