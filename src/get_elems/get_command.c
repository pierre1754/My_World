/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void move_command(void)
{
    engine_t *engine = get_engine();

    if (engine->event.type == sfEvtKeyPressed) {
        if (engine->event.key.code == sfKeyRight)
            GET_SET_PX(engine) += 20;
        if (engine->event.key.code == sfKeyLeft)
            GET_SET_PX(engine) -= 20;
        if (engine->event.key.code == sfKeyDown)
            GET_SET_PY(engine) += 20;
        if (engine->event.key.code == sfKeyUp)
            GET_SET_PY(engine) -= 20;
        resize_map();
    }
}