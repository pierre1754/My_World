/*
** EPITECH PROJECT, 2020
** draw_all.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void draw_each_map(int i, int j)
{
    engine_t *engine = get_engine();

    draw_shader(i, j);
    switch (engine->settings->draw_mode) {
    case texture:
        if (i + 1 != GET_SET_MX(engine) && j + 1 != GET_SET_MY(engine)) {
            engine->render->states.texture = GET_TEX_2D(engine)[i][j];
            sfRenderWindow_drawVertexArray(GET_WINDOW(engine),
            GET_MAP_TEX(engine)[i][j], &engine->render->states);
        }
        break;
    case color:
        if (i + 1 != GET_SET_MX(engine) && j + 1 != GET_SET_MY(engine))
            sfRenderWindow_drawVertexArray(GET_WINDOW(engine),
            GET_MAP_COLOR(engine)[i][j], NULL);
        break;
    }
    if (engine->settings->draw_line)
        sfRenderWindow_drawVertexArray(GET_WINDOW(engine),
            GET_MAP_LINES(engine)[i][j], NULL);
}

void draw_map(void)
{
    engine_t *engine = get_engine();
    static float time = 0;

    time += GET_ELAPSED(engine);
    sfShader_setFloatUniform(engine->shade->shader, "time", time);
    for (int i = 0; i < GET_SET_MX(engine); i++)
        for (int j = 0; j < GET_SET_MY(engine); j++)
            draw_each_map(i, j);
}
