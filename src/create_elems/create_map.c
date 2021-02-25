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

    engine->map->map_3d = malloc(sizeof(int *) * (GET_SET_MX(engine) + 1));
    engine->map->map_2d = malloc(sizeof(sfVector2f *) * (GET_SET_MX(engine) + 1));
    for (int i = 0; i < GET_SET_MX(engine); i++) {
        engine->map->map_3d[i] = malloc(sizeof(int) * (GET_SET_MY(engine) + 1));
        engine->map->map_2d[i] = malloc(sizeof(sfVector2f) * (GET_SET_MY(engine) + 1));
    }
}
