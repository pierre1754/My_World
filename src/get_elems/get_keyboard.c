/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void shortcut(void)
{
    engine_t *engine = get_engine();

    if (engine->event.key.control) {
        switch (engine->event.key.code) {
        case sfKeyO:
            increase_map_x();
            break;
        case sfKeyL:
            decrease_map_x();
            break;
        case sfKeyP:
            increase_map_y();
            break;
        case sfKeyM:
            decrease_map_y();
            break;
        default:
            break;
        }
    }
}

void get_keyboard(void)
{
    engine_t *engine = get_engine();

    if (engine->event.type == sfEvtKeyPressed) {
        key_move();
        key_zoom();
        key_map();
        key_save();
        shortcut();
        recalc_map();
    }
}
