/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void key_zoom(void)
{
    engine_t *engine = get_engine();

    if (engine->event.key.code == sfKeyPageUp)
        GET_SET_Z(engine) += GET_ELAPSED(engine) * 120;
    if (engine->event.key.code == sfKeyPageDown)
        GET_SET_Z(engine) -= GET_ELAPSED(engine) * 120;
}
