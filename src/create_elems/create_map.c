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
    GET_MAP_3D(engine) = malloc(sizeof(int *) * (GET_SET_MX(engine) + 1));
    GET_MAP_2D(engine) = malloc(sizeof(sfVector2f *) * (GET_SET_MX(engine) + 1));
    GET_MAP_VER(engine) = malloc(sizeof(sfVertexArray **) * (GET_SET_MX(engine) + 1));
    for (int i = 0; i < GET_SET_MX(engine); i++) {
        GET_MAP_3D(engine)[i] = malloc(sizeof(int) * (GET_SET_MY(engine) + 1));
        GET_MAP_2D(engine)[i] = malloc(sizeof(sfVector2f) * (GET_SET_MY(engine) + 1));
    }
    for (int i = 0; i < GET_SET_MX(engine) - 1; i++) {
        GET_MAP_VER(engine)[i] = malloc(sizeof(sfVertexArray *) * (GET_SET_MY(engine) + 1));
        for (int j = 0; j < GET_SET_MY(engine) - 1; j++) {
            GET_MAP_VER(engine)[i][j] = sfVertexArray_create();
        }
    }
}
