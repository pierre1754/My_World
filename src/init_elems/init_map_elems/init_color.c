/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void init_color_2d(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        for (int j = 0; j <= GET_SET_MY(engine); j++)
            GET_COLOR_2D(engine)[i][j] = get_color(GET_MAP_3D(engine)[i][j]);
    }
    GET_COLOR_2D(engine)[GET_SET_MX(engine)] = NULL;
}

void init_texture_2d(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        for (int j = 0; j < GET_SET_MY(engine); j++)
            GET_TEX_2D(engine)[i][j] = get_texture(GET_MAP_3D(engine)[i][j]);
    }
    GET_TEX_2D(engine)[GET_SET_MX(engine)] = NULL;
}
