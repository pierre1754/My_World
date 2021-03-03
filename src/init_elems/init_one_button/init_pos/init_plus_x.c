/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void init_plus_x_rect(engine_t *engine, buttons_t *button,
sfVector2f rect_size)
{
    button->pos = (sfVector2f){
        MARGE,
        GET_WINDOW_SIZE(engine).y - rect_size.y * 2 - MARGE * 2
    };
    sfRectangleShape_setPosition(button->rectangle, button->pos);
}

void init_plus_x_text(buttons_t *button,
sfVector2f rect_size)
{
    button->str_text = my_strdup("Increase X");
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

void init_plus_x(buttons_t *button)
{
    engine_t *engine = get_engine();
    sfVector2f rect_size = {0};

    sfRectangleShape_setSize(button->rectangle, (sfVector2f){150, 75});
    rect_size = sfRectangleShape_getSize(button->rectangle);
    button->act_funct = increase_map_x;
    init_plus_x_rect(engine, button, rect_size);
    init_plus_x_text(button, rect_size);
}

