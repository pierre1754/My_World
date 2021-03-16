/*
** EPITECH PROJECT, 2020
** draw_all.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void set_tex_button(void)
{
    engine_t *engine = get_engine();

    sfRectangleShape_setFillColor(BUT_AR(engine)[palette_color]->rectangle,
    sfWhite);
    sfRectangleShape_setTexture(BUT_AR(engine)[palette_color]->rectangle,
    GET_TEXTURE(engine), sfTrue);
}

void reset_tex_button(void)
{
    engine_t *engine = get_engine();

    sfRectangleShape_setFillColor(BUT_AR(engine)[palette_color]->rectangle,
    GET_COLOR(engine));
    sfRectangleShape_setTexture(BUT_AR(engine)[palette_color]->rectangle, NULL,
    sfTrue);
}
