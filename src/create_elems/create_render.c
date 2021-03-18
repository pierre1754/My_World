/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void create_render(void)
{
    engine_t *engine = get_engine();

    engine->render = malloc(sizeof(render_states_t));
    engine->render->dirt = sfTexture_createFromFile(DIRT, NULL);
    engine->render->grass = sfTexture_createFromFile(GRASS, NULL);
    engine->render->sand = sfTexture_createFromFile(SAND, NULL);
    engine->render->states = (sfRenderStates){
        .shader = NULL,
        .blendMode = sfBlendAlpha,
        .transform = sfTransform_Identity,
        .texture = engine->render->dirt,
    };
}

void create_shader(void)
{
    engine_t *engine = get_engine();

    engine->shade = malloc(sizeof(render_shader_t));
    engine->shade->water = sfTexture_createFromFile(WATER, NULL);
    engine->shade->shader = sfShader_createFromFile(NULL, NULL, SHADER_NAME);
    engine->shade->states = (sfRenderStates){
        .shader = engine->shade->shader,
        .blendMode = sfBlendAlpha,
        .transform = sfTransform_Identity,
        .texture = engine->shade->water,
    };
}
