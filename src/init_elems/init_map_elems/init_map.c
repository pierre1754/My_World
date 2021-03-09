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
    recalc_map();
}

void init_map_int(int **map)
{
    engine_t *engine = get_engine();

    if (GET_SET_LOD(engine)) {
        GET_SET_LOD(engine) = 0;
        return;
    }
    for (int i = 0; i < GET_SET_MX(engine); i++) {
        for (int j = 0; j <= GET_SET_MY(engine); j++) {
            map[i][j] = 0;
        }
    }
    map[GET_SET_MX(engine)] = NULL;
}

void calc_map_vec(sfVector2f **map, int **map_int)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        for (int j = 0; j < GET_SET_MY(engine); j++)
            map[i][j] = set_iso_point(i, j,
            map_int[i][j]);
    }
}

void init_map_ver(sfVertexArray ***map, sfVector2f **map_vec)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine) - 1; i++) {
        for (int j = 0; j < GET_SET_MY(engine) - 1; j++) {
            map[i][j] = create_vertex_quad((square_t){
                map_vec[i][j],
                map_vec[i][j + 1],
                map_vec[i + 1][j + 1],
                map_vec[i + 1][j]
            }, map[i][j], i, j);
        }
    }
}

void init_map_line(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        for (int j = 0; j < GET_SET_MY(engine); j++) {
            if (i + 1 != GET_SET_MX(engine)) {
                GET_MAP_LINES(engine)[i][j] = create_vertex_line((line_t){
                    GET_MAP_2D(engine)[i][j],
                    GET_MAP_2D(engine)[i + 1][j]
                }, GET_MAP_LINES(engine)[i][j]);
            }
            if (j + 1 != GET_SET_MY(engine)) {
                GET_MAP_LINES(engine)[i][j] = create_vertex_line((line_t){
                    GET_MAP_2D(engine)[i][j],
                    GET_MAP_2D(engine)[i][j + 1]
                }, GET_MAP_LINES(engine)[i][j]);
            }
        }
    }
}
