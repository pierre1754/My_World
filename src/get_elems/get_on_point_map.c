/*
** EPITECH PROJECT, 2020
** get_on_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void get_on_point_map(void)
{
    engine_t *engine = get_engine();
    sfVector2i mouse = sfMouse_getPositionRenderWindow(GET_WINDOW(engine));

    for (int i = 0; i < GET_SET_MX(engine) - 1; i++) {
        for (int j = 0; j < GET_SET_MY(engine) - 1; j++) {
            if (get_distance(GET_MAP_2D(engine)[i][j],
            (sfVector2f){mouse.x, mouse.y}) < 10) {
                GET_MAP_3D(engine)[i][j] += GET_ELAPSED(engine) * 100;
                GET_MAP_2D(engine)[i][j] = set_iso_point(i, j,
                GET_MAP_3D(engine)[i][j]);
            }
        }
    }
}

void get_on_point_map_minus(void)
{
    engine_t *engine = get_engine();
    sfVector2i mouse = sfMouse_getPositionRenderWindow(GET_WINDOW(engine));
    sfFloatRect temp_rect = {0};
    sfVector2f temp_vect = {0};

    for (int i = 1; i < GET_SET_MX(engine) - 1; i++) {
        for (int j = 1; j < GET_SET_MY(engine) - 1; j++) {
            temp_rect = sfVertexArray_getBounds(GET_MAP_TEX(engine)[i][j]);
            temp_vect = (sfVector2f){temp_rect.left + temp_rect.width / 2,
            temp_rect.top + temp_rect.height / 2};
            if (get_distance(temp_vect, (sfVector2f){mouse.x, mouse.y}) < 10) {
                GET_MAP_3D(engine)[i][j] -= GET_ELAPSED(engine) * 100;
                GET_MAP_2D(engine)[i][j] = set_iso_point(i, j,
                GET_MAP_3D(engine)[i][j]);
            }
        }
    }
}

void get_mouse_point_input(void)
{
    engine_t *engine = get_engine();

    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    !engine->settings->on_button)
        get_on_point_map();
    if (sfMouse_isButtonPressed(sfMouseRight) &&
    !engine->settings->on_button)
        get_on_point_map_minus();
    replace_map();
    for (int i = 0; i < GET_SET_MX(engine) - 1; i++)
        for (int j = 0; j < GET_SET_MY(engine) - 1; j++)
            set_texture_params(i, j);
}
