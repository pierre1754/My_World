/*
** EPITECH PROJECT, 2020
** draw_all.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void set_tex_button(void)
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
            sfRectangleShape_setFillColor(temp->rectangle, sfWhite);
            sfRectangleShape_setTexture(temp->rectangle,
            engine->render->states.texture, sfTrue);
        }
    }
}

void reset_tex_button(void)
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
            sfRectangleShape_setFillColor(temp->rectangle, GET_COLOR(engine));
            sfRectangleShape_setTexture(temp->rectangle, NULL, sfTrue);
        }
    }
}
