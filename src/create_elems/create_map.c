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
    create_map_3d();
    create_map_2d();
    GET_MAP_VER(engine) = create_map_ver();
    GET_MAP_LINES(engine) = create_map_ver();
    GET_MAP_ORIGIN(engine) = create_map_ver();
}

void create_map_3d(void)
{
    engine_t *engine = get_engine();

    GET_MAP_3D(engine) = malloc(sizeof(int *) * (GET_SET_MX(engine) + 1));
    for (int i = 0; i < GET_SET_MX(engine); i++)
        GET_MAP_3D(engine)[i] = malloc(sizeof(int) * (GET_SET_MY(engine) + 1));
    GET_MAP_3D(engine)[GET_SET_MX(engine)] = NULL;
}

void create_map_2d(void)
{
    engine_t *engine = get_engine();

    GET_MAP_2D(engine) = malloc(sizeof(sfVector2f *) *
    (GET_SET_MX(engine) + 1));
    for (int i = 0; i < GET_SET_MX(engine); i++)
        GET_MAP_2D(engine)[i] = malloc(sizeof(sfVector2f) *
        (GET_SET_MY(engine) + 1));
    GET_MAP_2D(engine)[GET_SET_MX(engine)] = NULL;
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
