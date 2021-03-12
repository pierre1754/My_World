/*
** EPITECH PROJECT, 2020
** draw_all.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void destroy_shader(void)
{
    engine_t *engine = get_engine();

    sfShader_destroy(engine->shade->shader);
    sfTexture_destroy(engine->shade->water);
}
