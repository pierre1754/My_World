/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

static const sfColor ar_color_palette[] = {
    (sfColor) {0, 0, 0, 255},
    (sfColor) {255, 255, 255, 255},
    (sfColor) {255, 0, 0, 255},
    (sfColor) {0, 255, 0, 255},
    (sfColor) {0, 0, 255, 255},
    (sfColor) {255, 255, 0, 255},
    (sfColor) {255, 0, 255, 255},
    (sfColor) {0, 255, 255, 255},
    (sfColor) {0, 0, 0, 0}
};

static void change_button_color(void)
{
    engine_t *engine = get_engine();
    sfVector2f rect_pos = {0};
    sfVector2f rect_size = {0};
    buttons_t *temp = NULL;

    LIST_FOREACH(temp, GET_LISTHEAD(engine), entries) {
        rect_pos = sfRectangleShape_getPosition(temp->rectangle);
        rect_size = sfRectangleShape_getSize(temp->rectangle);
        if ((rect_pos.x == (GET_WINDOW_SIZE(engine).x - rect_size.x - MARGE))
        && rect_pos.y == MARGE) {
            temp->color = GET_COLOR(engine);
        }
    }
}

void change_color_map(void)
{
    engine_t *engine = get_engine();
    static int color_id = 0;

    GET_COLOR(engine) = ar_color_palette[color_id];
    color_id = (color_id + 1) % 8;
    change_button_color();
}
