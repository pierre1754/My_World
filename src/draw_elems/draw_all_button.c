/*
** EPITECH PROJECT, 2020
** draw_all.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void draw_all_button(void)
{
    engine_t *engine = get_engine();

    if (GET_DRAW_BUTTON(engine)) {
        for (int i = 0; i < buttons; i++) {
            draw_button(BUT_AR(engine)[i], GET_WINDOW(engine));
        }
    }
}
