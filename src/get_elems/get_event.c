/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void get_event(void)
{
    engine_t *engine = get_engine();

    if (engine->event.type == sfEvtClosed)
        sfRenderWindow_close(GET_WINDOW(engine));
    get_button_evt();
    get_scroll();
    if (GET_LINE(engine))
        get_mouse_point_input();
    else
        get_mouse_input();
    get_keyboard();
}
