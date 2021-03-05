/*
** EPITECH PROJECT, 2020
** draw_all.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void draw_help(void)
{
    engine_t *engine = get_engine();

    if (GET_SET_STATUS(engine)) {
        set_pos_help_message();
        sfRenderWindow_drawText(GET_WINDOW(engine),
        engine->message->message, NULL);
    }
}
