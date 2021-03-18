/*
** EPITECH PROJECT, 2020
** get_on_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void replace_map(void)
{
    engine_t *engine = get_engine();

    switch (engine->settings->draw_mode) {
    case texture:
        clear_map_ver(GET_MAP_TEX(engine));
        init_map_tex(GET_MAP_TEX(engine), GET_MAP_2D(engine));
        break;
    case color:
        clear_map_ver(GET_MAP_COLOR(engine));
        init_map_color(GET_MAP_COLOR(engine), GET_MAP_2D(engine));
        break;
    }
    if (engine->settings->draw_line) {
        clear_map_ver(GET_MAP_LINES(engine));
        init_map_line();
    }
}

void get_mouse_input(void)
{
    engine_t *engine = get_engine();

    if (engine->settings->edit_mode) {
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
        !engine->settings->on_button)
            get_on_map();
        if (sfMouse_isButtonPressed(sfMouseRight) &&
        !engine->settings->on_button)
            get_on_map_minus();
    }
    else
        if (sfMouse_isButtonPressed(sfMouseLeft) &&
        !engine->settings->on_button)
            edit_map();
    replace_map();
    get_selection();
}

void change_color(int i, int j)
{
    engine_t *engine = get_engine();

    for (int a = 0; a < 4; a++) {
        sfVertexArray_getVertex(GET_MAP_COLOR(engine)[i][j], a)->color =
        sfColor_fromRGBA(12, 24, 255, 200);
        sfVertexArray_getVertex(GET_MAP_TEX(engine)[i][j], a)->color =
        sfColor_fromRGBA(170, 170, 170, 200);
    }
}

void get_selection(void)
{
    engine_t *engine = get_engine();
    sfVector2i mouse = sfMouse_getPositionRenderWindow(GET_WINDOW(engine));
    sfFloatRect temp_rect = {0};
    sfVector2f temp_vect = {0};
    float dist = 0;

    for (int i = 0; i < GET_SET_MX(engine) - 1; i++) {
        for (int j = 0; j < GET_SET_MY(engine) - 1; j++) {
            temp_rect = sfVertexArray_getBounds(GET_MAP_ORIGIN(engine)[i][j]);
            temp_vect = (sfVector2f){temp_rect.left + temp_rect.width / 2,
            temp_rect.top + temp_rect.height / 2};
            dist = get_distance(temp_vect, (sfVector2f){mouse.x, mouse.y});
            set_texture_params(i, j);
            if (dist < GET_SET_RAD(engine) &&
            dist > GET_SET_RAD(engine) - 20) {
                change_color(i, j);
            }
        }
    }
}
