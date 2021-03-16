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
    bool is_pressed = 0;

    if (GET_DRAW_BUTTON(engine)) {
        for (int i = 0; i < buttons; i++) {
            if (curser_on_button(BUT_AR(engine)[i], mouse_pos, engine->message))
                is_pressed = 1;
            click_on_button(BUT_AR(engine)[i], mouse_pos, engine->event);
        }
        if (is_pressed)
            GET_SET_STATUS(engine) = 1;
        else GET_SET_STATUS(engine) = 0;
    }
}
