/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void destroy_map(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        free(engine->map->map_3d[i]);
        free(engine->map->map_2d[i]);
    }
    free(engine->map->map_3d);
    free(engine->map->map_2d);
}
