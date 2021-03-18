/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void init_map_mode(button_t *button)
{
    engine_t *engine = get_engine();

    button->act_funct = change_draw_line;
    button->pos = (sfVector2f){
        GET_WINDOW_SIZE(engine).x - button->rect_size.x - MARGE,
        GET_WINDOW_SIZE(engine).y - button->rect_size.y - MARGE
    };
    sfRectangleShape_setPosition(button->rectangle, button->pos);
    button->str_text = my_strdup("Map Mode");
    button->help_message = my_strdup("Click to change the print mode");
}

void init_change_mode(button_t *button)
{
    engine_t *engine = get_engine();

    button->act_funct = change_draw_mode;
    button->pos = (sfVector2f){
        GET_WINDOW_SIZE(engine).x - button->rect_size.x * 2 - MARGE * 2,
        GET_WINDOW_SIZE(engine).y - button->rect_size.y - MARGE
    };
    sfRectangleShape_setPosition(button->rectangle, button->pos);
    button->str_text = my_strdup("Change Mode");
    button->help_message = my_strdup("Click to change the print mode");
}

void init_edit_mode(button_t *button)
{
    engine_t *engine = get_engine();

    button->act_funct = change_edit_mode;
    button->pos = (sfVector2f){
        GET_WINDOW_SIZE(engine).x - button->rect_size.x - MARGE,
        button->rect_size.y + 2 * MARGE
    };
    sfRectangleShape_setPosition(button->rectangle, button->pos);
    button->str_text = my_strdup("Edit Mode");
    button->help_message = my_strdup("Change Edit Mode");
}

void init_line_mode(button_t *button)
{
    engine_t *engine = get_engine();

    button->act_funct = change_line_mode;
    button->pos = (sfVector2f){
        GET_WINDOW_SIZE(engine).x - button->rect_size.x - MARGE,
        button->rect_size.y * 2 + 3 * MARGE
    };
    sfRectangleShape_setPosition(button->rectangle, button->pos);
    button->str_text = my_strdup("Line Mode");
    button->help_message = my_strdup("Change Line Mode");
}
