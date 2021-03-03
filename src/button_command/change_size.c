/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void resize_map(void)
{
    engine_t *engine = get_engine();

    GET_MAP_3D(engine) = intdup_2d(GET_MAP_3D(engine));
    GET_MAP_3D_BASE(engine) = intdup_2d(GET_MAP_3D_BASE(engine));
    GET_MAP_2D(engine) = vectordup_2d(GET_MAP_2D(engine));
    GET_MAP_2D_BASE(engine) = vectordup_2d(GET_MAP_2D_BASE(engine));
    GET_MAP_VER(engine) = vertexdup_2d();
    GET_MAP_LINES(engine) = linedup_2d();
    GET_MAP_ORIGIN(engine) = vertexdup_2d();
    init_map_2d();
    init_map_2d_base();
    init_map_ver(GET_MAP_VER(engine));
    init_map_ver_base(GET_MAP_ORIGIN(engine));
}

void increase_map_x(void)
{
    engine_t *engine = get_engine();

    if (GET_SET_MX(engine) > 0) {
        GET_SET_MX(engine) += 1;
        resize_map();
    }
}

void decrease_map_x(void)
{
    engine_t *engine = get_engine();

    if (GET_SET_MX(engine) > 0) {
        GET_SET_MX(engine) -= 1;
        resize_map();
    }
}

void increase_map_y(void)
{
    engine_t *engine = get_engine();

    if (GET_SET_MY(engine) > 0) {
        GET_SET_MY(engine) += 1;
        resize_map();
    }
}

void decrease_map_y(void)
{
    engine_t *engine = get_engine();

    if (GET_SET_MY(engine) > 0) {
        GET_SET_MY(engine) -= 1;
        resize_map();
    }
}
