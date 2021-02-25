/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void destroy_map(void)
{
    engine_t *engine = get_engine();

    destroy_map_3d();
    destroy_map_2d();
    destroy_map_ver();
    free(engine->map);
}

void destroy_map_3d(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine); i++)
        free(GET_MAP_3D(engine)[i]);
    free(GET_MAP_3D(engine));
}

void destroy_map_2d(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine); i++)
        free(GET_MAP_2D(engine)[i]);
    free(GET_MAP_2D(engine));
}

void destroy_map_ver(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine) - 1; i++) {
        for (int j = 0; j < GET_SET_MY(engine) - 1; j++)
            sfVertexArray_destroy(GET_MAP_VER(engine)[i][j]);
        free(GET_MAP_VER(engine)[i]);
    }
    free(GET_MAP_VER(engine));
}
