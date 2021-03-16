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
        if (GET_SET_MODE(engine) == texture)
            set_tex_button();
        else
            reset_tex_button();
        for (int i = 0; i < buttons; i++) {
            draw_button(BUT_AR(engine)[i], GET_WINDOW(engine));
        }
    }
}
