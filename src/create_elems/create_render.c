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
    engine->render->dirt = sfTexture_createFromFile("asset/dirt.png", NULL);
    engine->render->grass = sfTexture_createFromFile("asset/grass.png", NULL);
    engine->render->sand = sfTexture_createFromFile("asset/sand.png", NULL);
    engine->render->states = (sfRenderStates){
        .shader = NULL,
        .blendMode = sfBlendAlpha,
        .transform = sfTransform_Identity,
        .texture = engine->render->dirt,
    };
}