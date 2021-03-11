/*
** EPITECH PROJECT, 2020
** draw_all.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void draw_elem(void)
{
    engine_t *engine = get_engine();

    sfRenderWindow_clear(GET_WINDOW(engine), sfBlack);
    draw_map();
    draw_button(GET_LISTHEAD(engine)->lh_first, GET_WINDOW(engine));
    draw_text(GET_LISTHEAD(engine)->lh_first, GET_WINDOW(engine));
    draw_help();
    sfShader_setFloatParameter(engine->shade->shader, "time", GET_ELAPSED(engine) * 10000);
    sfRenderWindow_drawVertexArray(GET_WINDOW(engine), GET_MAP_TEX(engine)[1][1], &engine->shade->states);
    sfRenderWindow_display(GET_WINDOW(engine));
}
