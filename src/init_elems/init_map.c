/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void init_map(void)
{
    init_map_3d();
    init_map_2d();
    init_map_ver();
    init_map_line();
}

void init_map_3d(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        for (int j = 0; j < GET_SET_MY(engine); j++)
            GET_MAP_3D(engine)[i][j] = 0;
        GET_MAP_3D(engine)[i][GET_SET_MY(engine)] = '\0';
    }
}

void init_map_2d(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        for (int j = 0; j < GET_SET_MY(engine); j++)
            GET_MAP_2D(engine)[i][j] = get_iso_point(i, j,
            GET_MAP_3D(engine)[i][j]);
    }
}

void init_map_ver(void)
{
    engine_t *engine = get_engine();
    square_t *temp = NULL;

    for (int i = 0; i < GET_SET_MX(engine) - 1; i++) {
        for (int j = 0; j < GET_SET_MY(engine) - 1; j++) {
            temp = create_quad(GET_MAP_2D(engine)[i][j],
            GET_MAP_2D(engine)[i][j + 1], GET_MAP_2D(engine)[i + 1][j + 1],
            GET_MAP_2D(engine)[i + 1][j]);
            GET_MAP_VER(engine)[i][j] = create_vertex_quad(temp,
            GET_MAP_VER(engine)[i][j], i, j);
        }
    }
}

void init_map_line(void)
{
    engine_t *engine = get_engine();
    line_t *temp = NULL;

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        for (int j = 0; j < GET_SET_MY(engine); j++) {
            if (i + 1 != GET_SET_MX(engine)) {
                temp = create_line(GET_MAP_2D(engine)[i][j],
                GET_MAP_2D(engine)[i + 1][j]);
                GET_MAP_LINES(engine)[i][j] = create_vertex_line(temp,
                GET_MAP_LINES(engine)[i][j]);
            }
            if (j + 1 != GET_SET_MY(engine)) {
                temp = create_line(GET_MAP_2D(engine)[i][j],
                GET_MAP_2D(engine)[i][j + 1]);
                GET_MAP_LINES(engine)[i][j] = create_vertex_line(temp,
                GET_MAP_LINES(engine)[i][j]);
            }
        }
    }
}
