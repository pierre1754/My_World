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

    for (int i = 0; i < GET_SET_MX(engine) - 1; i++)
        for (int j = 0; j < GET_SET_MY(engine) - 1; j++) {
            temp_rect = sfVertexArray_getBounds(GET_MAP_ORIGIN(engine)[i][j]);
            temp_vect = (sfVector2f){temp_rect.left + temp_rect.width / 2,
            temp_rect.top + temp_rect.height / 2};
            if (get_distance(temp_vect, (sfVector2f){mouse.x, mouse.y}) <
            GET_SET_RAD(engine)) {
                GET_MAP_3D(engine)[i][j] += GET_ELAPSED(engine) * 100;
                calc_map_vec(GET_MAP_2D(engine), GET_MAP_3D(engine));
            }
        }
}

void get_mouse_input(void)
{
    engine_t *engine = get_engine();

    if (sfMouse_isButtonPressed(sfMouseLeft) && !engine->settings->on_button) {
        get_on_map();
    }
    clear_map_ver(GET_MAP_VER(engine));
    clear_map_ver(GET_MAP_LINES(engine));
    init_map_ver(GET_MAP_VER(engine), GET_MAP_2D(engine));
    init_map_line();
    get_selection();
}

static void change_color(int i, int j)
{
    engine_t *engine = get_engine();

    for (int a = 0; a < 4; a++) {
        sfVertexArray_getVertex(GET_MAP_VER(engine)[i][j], a)->color =
        sfColor_fromRGBA(12, 24, 255, 200);
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
            if (dist < GET_SET_RAD(engine) &&
            dist > GET_SET_RAD(engine) - 20) {
                change_color(i, j);
            }
        }
    }
}
