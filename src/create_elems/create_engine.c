/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

engine_t *get_engine(void)
{
    static engine_t *engine = NULL;

    if (!engine)
        engine = malloc(sizeof(engine_t));
    return engine;
}

void create_engine(void)
{
    create_window();
    create_settings();
    create_buttons();
    create_map();
    create_time();
    create_help_message();
    create_render();
}
