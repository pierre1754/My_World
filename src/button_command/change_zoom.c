/*
** EPITECH PROJECT, 2020
** change_zoom.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void increase_zoom(void)
{
    engine_t *engine = get_engine();

    GET_SET_Z(engine)++;
    recalc_map();
}

void decrease_zoom(void)
{
    engine_t *engine = get_engine();

    if (GET_SET_Z(engine) - 1 > 0) {
        GET_SET_Z(engine)--;
        recalc_map();
    }
}
