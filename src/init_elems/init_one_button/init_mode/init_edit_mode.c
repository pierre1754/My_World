/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void init_edit_mode_rect(engine_t *engine, buttons_t *button,
sfVector2f rect_size)
{
    button->pos = (sfVector2f){
        GET_WINDOW_SIZE(engine).x - rect_size.x - MARGE,
        rect_size.y + 2 * MARGE
    };
    sfRectangleShape_setPosition(button->rectangle, button->pos);
}

void init_edit_mode_text(buttons_t *button,
sfVector2f rect_size)
{
    button->str_text = my_strdup("Edit Mode");
    button->help_message = my_strdup("Change Edit Mode");
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

void init_edit_mode(buttons_t *button)
{
    engine_t *engine = get_engine();
    sfVector2f rect_size = {0};

    rect_size = sfRectangleShape_getSize(button->rectangle);
    button->act_funct = change_edit_mode;
    init_edit_mode_rect(engine, button, rect_size);
    init_edit_mode_text(button, rect_size);
}
