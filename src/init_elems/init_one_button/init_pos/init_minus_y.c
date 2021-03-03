/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void init_minus_y_rect(engine_t *engine, buttons_t *button,
sfVector2f rect_size)
{
    button->pos = (sfVector2f){
        rect_size.x + MARGE * 2,
        GET_WINDOW_SIZE(engine).y - rect_size.y - MARGE
    };
    sfRectangleShape_setPosition(button->rectangle, button->pos);
}

void init_minus_y_text(buttons_t *button,
sfVector2f rect_size)
{
    button->str_text = my_strdup("Decrease Y");
    sfText_setString(button->text, button->str_text);
    sfText_setOrigin(button->text, (sfVector2f){
        sfText_getGlobalBounds(button->text).width / 2,
        sfText_getGlobalBounds(button->text).height / 2 + MARGE / 2
    });
    sfText_setPosition(button->text, (sfVector2f){
        button->pos.x + rect_size.x / 2,
        button->pos.y + rect_size.y / 2
    });
}

void init_minus_y(buttons_t *button)
{
    engine_t *engine = get_engine();
    sfVector2f rect_size = {0};

    rect_size = sfRectangleShape_getSize(button->rectangle);
    button->act_funct = decrease_map_y;
    init_minus_y_rect(engine, button, rect_size);
    init_minus_y_text(button, rect_size);
}
