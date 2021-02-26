/*
** EPITECH PROJECT, 2020
** button_command.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void enlarge_map_x(void)
{
    engine_t *engine = get_engine();

    if (GET_SET_MY(engine) > 0) {
        GET_SET_MY(engine) += 1;
        GET_MAP_3D(engine) = intdup_2d(GET_MAP_3D(engine));
        GET_MAP_2D(engine) = vectordup_2d(GET_MAP_2D(engine));
        GET_MAP_VER(engine) = vertexdup_2d(GET_MAP_VER(engine));
        //GET_SET_MY(engine) -= 1;
        //init_map_3d();
        init_map_2d();
        init_map_ver();
    }
}
