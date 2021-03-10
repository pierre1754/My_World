/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void key_move(void)
{
    engine_t *engine = get_engine();

    switch (engine->event.key.code) {
    case sfKeyRight:
        GET_SET_PX(engine) += GET_ELAPSED(engine) * 1000;
        break;
    case sfKeyLeft:
        GET_SET_PX(engine) -= GET_ELAPSED(engine) * 1000;
        break;
    case sfKeyDown:
        GET_SET_PY(engine) += GET_ELAPSED(engine) * 1000;
        break;
    case sfKeyUp:
        GET_SET_PY(engine) -= GET_ELAPSED(engine) * 1000;
        break;
    default:
        break;
    }
}
