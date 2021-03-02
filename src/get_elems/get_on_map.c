/*
** EPITECH PROJECT, 2020
** get_on_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void get_on_map(void)
{
    engine_t *engine = get_engine();
    sfVector2i mouse = sfMouse_getPositionRenderWindow(GET_WINDOW(engine));
    sfFloatRect temp_rect = {0};

    for (int i = 0; i < GET_SET_MX(engine) - 1; i++)
        for (int j = 0; j < GET_SET_MY(engine) - 1; j++) {
            temp_rect = sfVertexArray_getBounds(GET_MAP_VER(engine)[i][j]);
            if (sfFloatRect_contains(&temp_rect, mouse.x, mouse.y)) {
                GET_MAP_3D(engine)[i][j] += 1;
                init_map_2d();
            }
        }
}

void get_mouse_input(void)
{
    engine_t *engine = get_engine();

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        get_on_map();
    }
    GET_MAP_VER(engine) = clear_map_ver(GET_MAP_VER(engine));
    GET_MAP_LINES(engine) = clear_map_ver(GET_MAP_LINES(engine));
    init_map_ver();
    init_map_line();
    get_selection();
}

void draw_selection(sfVector2i pos)
{
    engine_t *engine = get_engine();
    sfVector2i mouse = sfMouse_getPositionRenderWindow(GET_WINDOW(engine));
    sfFloatRect temp_rect = {0};

    for (int i = 0; i < GET_SET_MX(engine) - 1; i++)
        for (int j = 0; j < GET_SET_MY(engine) - 1; j++) {
            temp_rect = sfVertexArray_getBounds(GET_MAP_VER(engine)[i][j]);
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

void get_selection(void)
{
    sfVector2i offset = {0, 0};
    int angle = 0;

    for (; angle <= 360; angle += 20) {
        offset.x = cos(angle * 3.14 / 180) * 100;
        offset.y = sin(angle * 3.14 / 180) * 100;
        draw_selection(offset);
    }
}
