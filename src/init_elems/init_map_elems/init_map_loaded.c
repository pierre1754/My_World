/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void init_map_loaded(void)
{
    engine_t *engine = get_engine();

    // init_map_int(GET_MAP_3D(engine));
    // PUT_MAP_HERE
    init_map_int(GET_MAP_3D_BASE(engine));
    calc_map_vec(GET_MAP_2D(engine), GET_MAP_3D(engine));
    calc_map_vec(GET_MAP_2D_BASE(engine), GET_MAP_3D_BASE(engine));
    init_map_ver(GET_MAP_VER(engine), GET_MAP_2D(engine));
    init_map_ver(GET_MAP_ORIGIN(engine), GET_MAP_2D_BASE(engine));
    init_map_line();
}
