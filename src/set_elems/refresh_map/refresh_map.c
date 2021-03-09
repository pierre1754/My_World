/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void recalc_map(void)
{
    engine_t *engine = get_engine();

    clear_map_lines(GET_MAP_LINES(engine));
    calc_map_vec(GET_MAP_2D(engine), GET_MAP_3D(engine));
    calc_map_vec(GET_MAP_2D_BASE(engine), GET_MAP_3D_BASE(engine));
    refresh_map_ver(GET_MAP_COLOR(engine), GET_MAP_2D(engine));
    refresh_map_ver(GET_MAP_TEX(engine), GET_MAP_2D(engine));
    refresh_map_ver(GET_MAP_ORIGIN(engine), GET_MAP_2D_BASE(engine));
    refresh_map_line();
}
