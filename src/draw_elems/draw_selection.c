/*
** EPITECH PROJECT, 2020
** draw_all.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void draw_selection(sfVector2i pos)
{
    engine_t *engine = get_engine();
    sfVector2i mouse = sfMouse_getPositionRenderWindow(GET_WINDOW(engine));
    sfFloatRect temp_rect = {0};

    for (int i = 0; i < GET_SET_MX(engine) - 1; i++)
        for (int j = 0; j < GET_SET_MY(engine) - 1; j++) {
            temp_rect = sfVertexArray_getBounds(GET_MAP_ORIGIN(engine)[i][j]);
            if (sfFloatRect_contains(&temp_rect, mouse.x + pos.x, mouse.y +
            pos.y)) {
                sfVertexArray_getVertex(GET_MAP_VER(engine)[i][j], 0)->color =
                sfColor_fromRGBA(12, 24, 255, 200);
                sfVertexArray_getVertex(GET_MAP_VER(engine)[i][j], 1)->color =
                sfColor_fromRGBA(12, 24, 255, 200);
                sfVertexArray_getVertex(GET_MAP_VER(engine)[i][j], 2)->color =
                sfColor_fromRGBA(12, 24, 255, 200);
                sfVertexArray_getVertex(GET_MAP_VER(engine)[i][j], 3)->color =
                sfColor_fromRGBA(12, 24, 255, 200);
            }
        }
}
