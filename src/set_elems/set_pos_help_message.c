/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void set_pos_help_message(void)
{
    engine_t *engine = get_engine();
    sfVector2i pos = sfMouse_getPositionRenderWindow(GET_WINDOW(engine));

    sfText_setPosition(engine->message->message,
    (sfVector2f){
        pos.x + 20,
        pos.y
    });
}
