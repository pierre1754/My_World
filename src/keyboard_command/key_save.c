/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void key_save(void)
{
    engine_t *engine = get_engine();

    if (engine->event.key.control) {
        switch (engine->event.key.code) {
        case sfKeyS:
            save_map();
            break;
        default:
            break;
        }
    }
}
