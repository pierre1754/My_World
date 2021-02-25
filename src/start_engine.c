/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void start_engine(void)
{
    engine_t *engine = get_engine();

    while (sfRenderWindow_isOpen(GET_WINDOW(engine))) {
        while (sfRenderWindow_pollEvent(GET_WINDOW(engine), &engine->event)) {
            get_event();
        }
        get_elem();
        set_elem();
        draw_elem();
        // CODE HERE
    }
}
