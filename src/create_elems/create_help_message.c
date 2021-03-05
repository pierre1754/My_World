/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void create_help_message(void)
{
    engine_t *engine = get_engine();

    engine->message = malloc(sizeof(help_message_t));
    engine->message->message = sfText_create();
    engine->message->font = sfFont_createFromFile("asset/button_font.ttf");
    sfText_setFont(engine->message->message, engine->message->font);
    engine->message->is_printable = 0;
}
