/*
** EPITECH PROJECT, 2020
** draw_all.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void draw_shader(int i, int j)
{
    engine_t *engine = get_engine();

    if (i + 1 != GET_SET_MX(engine) && j + 1 != GET_SET_MY(engine) &&
    GET_MAP_3D(engine)[i][j] <= 0 && (GET_MAP_3D(engine)[i + 1][j] < 0 ||
    GET_MAP_3D(engine)[i][j + 1] < 0))
        sfRenderWindow_drawVertexArray(GET_WINDOW(engine),
        GET_MAP_ORIGIN(engine)[i][j], &engine->shade->states);
}
