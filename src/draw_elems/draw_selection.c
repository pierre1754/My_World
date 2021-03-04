/*
** EPITECH PROJECT, 2020
** draw_all.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

static void change_color(int i, int j)
{
    engine_t *engine = get_engine();

    for (int a = 0; a < 4; a++) {
        sfVertexArray_getVertex(GET_MAP_VER(engine)[i][j], a)->color =
        sfColor_fromRGBA(12, 24, 255, 200);
    }
}

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
                change_color(i, j);
            }
        }
}
