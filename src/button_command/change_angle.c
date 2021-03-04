/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void change_angle(void)
{
    engine_t *engine = get_engine();

    //clear_map_ver(GET_MAP_VER(engine));
    init_map_2d();
    init_map_2d_base();
    init_map_ver(GET_MAP_VER(engine));
    init_map_ver_base(GET_MAP_ORIGIN(engine));
    clear_map_ver(GET_MAP_LINES(engine));
    init_map_line();
}

void increase_angle_x(void)
{
    engine_t *engine = get_engine();

    GET_SET_AX(engine) += GET_ELAPSED(engine) * 100;
    change_angle();
}

void decrease_angle_x(void)
{
    engine_t *engine = get_engine();

    GET_SET_AX(engine) -= GET_ELAPSED(engine) * 100;
    change_angle();
}

void increase_angle_y(void)
{
    engine_t *engine = get_engine();

    GET_SET_AY(engine)++;
    change_angle();
}

void decrease_angle_y(void)
{
    engine_t *engine = get_engine();

    GET_SET_AY(engine)--;
    change_angle();
}
