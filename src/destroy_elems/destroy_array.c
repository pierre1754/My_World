/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void destroy_array(void)
{
    engine_t *engine = get_engine();

    destroy_map_ver(GET_MAP_COLOR(engine));
    destroy_map_ver(GET_MAP_TEX(engine));
    destroy_map_ver(GET_MAP_ORIGIN(engine));
    destroy_map_ver(GET_MAP_LINES(engine));
}
