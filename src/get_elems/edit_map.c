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
    sfVector2f temp_vect = {0};

    for (int i = 1; i < GET_SET_MX(engine) - 1; i++) {
        for (int j = 1; j < GET_SET_MY(engine) - 1; j++) {
            temp_rect = sfVertexArray_getBounds(GET_MAP_ORIGIN(engine)[i][j]);
            temp_vect = (sfVector2f){temp_rect.left + temp_rect.width / 2,
            temp_rect.top + temp_rect.height / 2};
            if (get_distance(temp_vect, (sfVector2f){mouse.x, mouse.y}) <
            GET_SET_RAD(engine)) {
                GET_MAP_3D(engine)[i][j] += GET_ELAPSED(engine) * 100;
                GET_MAP_2D(engine)[i][j] = set_iso_point(i, j,
                GET_MAP_3D(engine)[i][j]);
            }
        }
    }
}

void get_on_map_minus(void)
{
    engine_t *engine = get_engine();
    sfVector2i mouse = sfMouse_getPositionRenderWindow(GET_WINDOW(engine));
    sfFloatRect temp_rect = {0};
    sfVector2f temp_vect = {0};

    for (int i = 1; i < GET_SET_MX(engine) - 1; i++) {
        for (int j = 1; j < GET_SET_MY(engine) - 1; j++) {
            temp_rect = sfVertexArray_getBounds(GET_MAP_ORIGIN(engine)[i][j]);
            temp_vect = (sfVector2f){temp_rect.left + temp_rect.width / 2,
            temp_rect.top + temp_rect.height / 2};
            if (get_distance(temp_vect, (sfVector2f){mouse.x, mouse.y}) <
            GET_SET_RAD(engine)) {
                GET_MAP_3D(engine)[i][j] -= GET_ELAPSED(engine) * 100;
                GET_MAP_2D(engine)[i][j] = set_iso_point(i, j,
                GET_MAP_3D(engine)[i][j]);
            }
        }
    }
}

void edit_map(void)
{
    engine_t *engine = get_engine();

    switch (engine->settings->draw_mode) {
    case texture:
        edit_texture_map();
        play_sound();
        break;
    case color:
        edit_color_map();
        break;
    default:
        break;
    }
}

void edit_color_map(void)
{
    engine_t *engine = get_engine();
    sfVector2i mouse = sfMouse_getPositionRenderWindow(GET_WINDOW(engine));
    sfFloatRect temp_rect = {0};
    sfVector2f temp_vect = {0};

    for (int i = 1; i < GET_SET_MX(engine); i++) {
        for (int j = 1; j < GET_SET_MY(engine); j++) {
            temp_rect = sfVertexArray_getBounds(GET_MAP_ORIGIN(engine)[i][j]);
            temp_vect = (sfVector2f){temp_rect.left + temp_rect.width / 2,
            temp_rect.top + temp_rect.height / 2};
            if (get_distance(temp_vect, (sfVector2f){mouse.x, mouse.y}) <
            GET_SET_RAD(engine)) {
                GET_COLOR_2D(engine)[i][j] = engine->settings->color;
            }
        }
    }
}

void edit_texture_map(void)
{
    engine_t *engine = get_engine();
    sfVector2i mouse = sfMouse_getPositionRenderWindow(GET_WINDOW(engine));
    sfFloatRect temp_rect = {0};
    sfVector2f temp_vect = {0};

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        for (int j = 0; j < GET_SET_MY(engine); j++) {
            temp_rect = sfVertexArray_getBounds(GET_MAP_ORIGIN(engine)[i][j]);
            temp_vect = (sfVector2f){temp_rect.left + temp_rect.width / 2,
            temp_rect.top + temp_rect.height / 2};
            if (get_distance(temp_vect, (sfVector2f){mouse.x, mouse.y}) <
            GET_SET_RAD(engine)) {
                GET_TEX_2D(engine)[i][j] = GET_TEXTURE(engine);
            }
        }
    }
}
