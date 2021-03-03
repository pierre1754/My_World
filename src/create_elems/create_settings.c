/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void create_settings(void)
{
    engine_t *engine = get_engine();

    engine->settings = malloc(sizeof(settings_t));
    memset(engine->settings, 0, sizeof(int) * nbr_int_settings);
    GET_SET_AX(engine) = 45;
    GET_SET_AY(engine) = 45;
    GET_SET_MX(engine) = 24;
    GET_SET_MY(engine) = 24;
    GET_SET_PX(engine) = 600;
    GET_SET_PY(engine) = 100;
    GET_SET_Z(engine) = 25;
    GET_SET_STATUS(engine) = 0;
    GET_SET_LINE(engine) = 1;
    GET_SET_MODE(engine) = 1;
}
