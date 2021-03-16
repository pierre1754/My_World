/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void get_button_evt(void)
{
    engine_t *engine = get_engine();
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(GET_WINDOW(engine));

    if (GET_DRAW_BUTTON(engine)) {
        for (int i = 0; i < buttons; i++) {
            curser_on_button(BUT_AR(engine)[i], mouse_pos, engine->message);
            click_on_button(BUT_AR(engine)[i], mouse_pos, engine->event);
        }
    }
}
