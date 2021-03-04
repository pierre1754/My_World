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

    init_map_2d();
    init_map_2d_base();
    clear_map_lines(GET_MAP_LINES(engine));
    clear_map_ver(GET_MAP_VER(engine));
    clear_map_ver(GET_MAP_ORIGIN(engine));
    init_map_ver(GET_MAP_VER(engine));
    init_map_ver_base(GET_MAP_ORIGIN(engine));
    init_map_line();
}

void increase_angle_x(void)
{
    engine_t *engine = get_engine();

    GET_SET_AX(engine) += GET_ELAPSED(engine) * 120;
    recalc_map();
}

void decrease_angle_x(void)
{
    engine_t *engine = get_engine();

    GET_SET_AX(engine) -= GET_ELAPSED(engine) * 120;
    recalc_map();
}

void increase_angle_y(void)
{
    engine_t *engine = get_engine();

    GET_SET_AY(engine) += GET_ELAPSED(engine) * 120;
    recalc_map();
}

void decrease_angle_y(void)
{
    engine_t *engine = get_engine();

    GET_SET_AY(engine) -= GET_ELAPSED(engine) * 120;
    recalc_map();
}
