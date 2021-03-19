/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

static void map_settings(void)
{
    engine_t *engine = get_engine();

    GET_SET_AX(engine) = 45;
    GET_SET_AY(engine) = 20;
    GET_SET_MX(engine) = 10;
    GET_SET_MY(engine) = 10;
    GET_SET_PX(engine) = 700;
    GET_SET_PY(engine) = 200;
    GET_SET_Z(engine) = 24;
    GET_LINE(engine) = 0;
}

void create_settings(void)
{
    engine_t *engine = get_engine();

    engine->settings = malloc(sizeof(settings_t));
    memset(engine->settings, 0, sizeof(int) * nbr_int_settings);
    map_settings();
    GET_SET_STATUS(engine) = 0;
    GET_SET_LINE(engine) = 0;
    GET_DEPTH(engine) = 4.f;
    GET_FREQ(engine) = 0.02f;
    GET_SET_MODE(engine) = 1;
    GET_SET_RAD(engine) = 100;
    GET_COLOR(engine) = sfWhite;
    GET_EDIT_MODE(engine) = 1;
    GET_DRAW_BUTTON(engine) = 1;
    GET_COLOR_ID(engine) = 0;
    GET_TEXTURE(engine) = engine->texture_palette[GET_COLOR_ID(engine)];
}
