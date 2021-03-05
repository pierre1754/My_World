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
        key_move();
        key_zoom();
        recalc_map();
    }
}
