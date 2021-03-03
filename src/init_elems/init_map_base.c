/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void init_map_3d_base(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        for (int j = 0; j < GET_SET_MY(engine); j++)
            GET_MAP_3D_BASE(engine)[i][j] = 0;
        GET_MAP_3D_BASE(engine)[i][GET_SET_MY(engine)] = '\0';
    }
}

void init_map_2d_base(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        for (int j = 0; j < GET_SET_MY(engine); j++)
            GET_MAP_2D_BASE(engine)[i][j] = set_iso_point(i, j,
            GET_MAP_3D_BASE(engine)[i][j]);
    }
}

void init_map_ver_base(sfVertexArray ***map)
{
    engine_t *engine = get_engine();
    square_t *temp = NULL;

    for (int i = 0; i < GET_SET_MX(engine) - 1; i++) {
        for (int j = 0; j < GET_SET_MY(engine) - 1; j++) {
            temp = create_quad(GET_MAP_2D_BASE(engine)[i][j],
            GET_MAP_2D_BASE(engine)[i][j + 1], GET_MAP_2D_BASE(engine)[i + 1]
            [j + 1], GET_MAP_2D_BASE(engine)[i + 1][j]);
            map[i][j] = create_vertex_quad(temp, map[i][j], i, j);
        }
    }
}
