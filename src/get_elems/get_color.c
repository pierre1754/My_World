/*
** EPITECH PROJECT, 2020
** get_vertex.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

sfColor get_color(int hight)
{
    if (hight >= 12)
        return sfColor_fromRGB(255, 255, 255);
    else if (hight < 12 && hight > 3)
        return sfColor_fromRGB(128, 128, 128);
    else
        return sfColor_fromRGB(64, 64, 64);
}

sfTexture *get_texture(int hight)
{
    engine_t *engine = get_engine();

    if (hight >= 12)
        return engine->render->grass;
    else if (hight < 12 && hight > 3)
        return engine->render->dirt;
    else
        return engine->render->sand;
}
