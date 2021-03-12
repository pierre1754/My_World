/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void key_map(void)
{
    engine_t *engine = get_engine();

    switch (engine->event.key.code) {
    case sfKeyR:
        init_map();
        break;
    case sfKeyT:
        init_perlin();
        break;
    default:
        break;
    }
}
