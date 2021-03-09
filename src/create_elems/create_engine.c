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
    engine_t *engine = get_engine();

    create_window();
    create_settings();
    create_buttons();
    create_map();
    create_time();
    create_help_message();
    engine->tex = sfTexture_createFromFile("asset/dirt.png", NULL);
    engine->states = (sfRenderStates){
        .shader = NULL,
        .blendMode = sfBlendAlpha,
        .transform = sfTransform_Identity,
        .texture = engine->tex,
    };
}
