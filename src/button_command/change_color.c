/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

static const sfColor ar_color_palette[] = {
    (sfColor) {0, 0, 0, 255},
    (sfColor) {255, 255, 255, 255},
    (sfColor) {255, 0, 0, 255},
    (sfColor) {0, 255, 0, 255},
    (sfColor) {0, 0, 255, 255},
    (sfColor) {255, 255, 0, 255},
    (sfColor) {255, 0, 255, 255},
    (sfColor) {0, 255, 255, 255},
    (sfColor) {0, 0, 0, 0}
};

void change_color_map(void)
{
    engine_t *engine = get_engine();

    GET_COLOR_ID(engine) = (GET_COLOR_ID(engine) + 1) % 9;
    GET_COLOR(engine) = ar_color_palette[GET_COLOR_ID(engine)];
    GET_TEXTURE(engine) = engine->texture_palette[GET_COLOR_ID(engine)];
    GET_SOUND(engine) = engine->sounds[GET_COLOR_ID(engine)];
    BUT_AR(engine)[palette_color]->color = GET_COLOR(engine);
}
