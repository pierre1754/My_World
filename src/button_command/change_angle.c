/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

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
