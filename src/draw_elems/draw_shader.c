/*
** EPITECH PROJECT, 2020
** draw_all.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void draw_shader(void)
{
    engine_t *engine = get_engine();
    static float time = 0;

    time += GET_ELAPSED(engine);
    sfShader_setFloatUniform(engine->shade->shader, "time", time);
    sfRenderWindow_drawVertexArray(GET_WINDOW(engine),
    GET_MAP_TEX(engine)[1][1], &engine->shade->states);
}
