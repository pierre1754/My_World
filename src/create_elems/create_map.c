/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void create_map(void)
{
    engine_t *engine = get_engine();

    engine->map = malloc(sizeof(map_t));
    GET_MAP_3D(engine) = create_map_3d();
    GET_MAP_3D_BASE(engine) = create_map_3d();
    GET_MAP_2D(engine) = create_map_2d();
    GET_MAP_2D_BASE(engine) = create_map_2d();
    GET_MAP_VER(engine) = create_map_ver();
    GET_MAP_TEX(engine) = create_map_ver();
    GET_MAP_LINES(engine) = create_map_ver();
    GET_MAP_ORIGIN(engine) = create_map_ver();
}

int **create_map_3d(void)
{
    engine_t *engine = get_engine();
    int **map = malloc(sizeof(int *) * (GET_SET_MX(engine) + 1));

    for (int i = 0; i < GET_SET_MX(engine); i++)
        map[i] = malloc(sizeof(int) * (GET_SET_MY(engine) + 1));
    map[GET_SET_MX(engine)] = NULL;
    return map;
}

sfVector2f **create_map_2d(void)
{
    engine_t *engine = get_engine();
    sfVector2f **map = malloc(sizeof(sfVector2f *) * (GET_SET_MX(engine) + 1));

    for (int i = 0; i < GET_SET_MX(engine); i++)
        map[i] = malloc(sizeof(sfVector2f) *
        (GET_SET_MY(engine) + 1));
    map[GET_SET_MX(engine)] = NULL;
    return map;
}

sfVertexArray ***create_map_ver(void)
{
    engine_t *engine = get_engine();
    sfVertexArray ***map = malloc(sizeof(sfVertexArray **) *
    (GET_SET_MX(engine) + 1));

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        map[i] = malloc(sizeof(sfVertexArray *) * (GET_SET_MY(engine) + 1));
        for (int j = 0; j < GET_SET_MY(engine); j++)
            map[i][j] = sfVertexArray_create();
    }
    map[GET_SET_MX(engine)] = NULL;
    return map;
}
