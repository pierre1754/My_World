/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void init_m_pos_x(button_t *button)
{
    engine_t *engine = get_engine();

    button->act_funct = decrease_map_x;
    button->pos = (sfVector2f){
        MARGE,
        GET_WINDOW_SIZE(engine).y - button->rect_size.y - MARGE
    };
    sfRectangleShape_setPosition(button->rectangle, button->pos);
    button->str_text = my_strdup("Decrease X");
    button->help_message = my_strdup("Click to decrease X");
}

void init_m_pos_y(button_t *button)
{
    engine_t *engine = get_engine();

    button->act_funct = decrease_map_y;
    button->pos = (sfVector2f){
        button->rect_size.x + MARGE * 2,
        GET_WINDOW_SIZE(engine).y - button->rect_size.y - MARGE
    };
    sfRectangleShape_setPosition(button->rectangle, button->pos);
    button->str_text = my_strdup("Decrease Y");
    button->help_message = my_strdup("Click to decrease Y");
}

void init_p_pos_x(button_t *button)
{
    engine_t *engine = get_engine();

    button->act_funct = increase_map_x;
    button->pos = (sfVector2f){
        MARGE,
        GET_WINDOW_SIZE(engine).y - button->rect_size.y * 2 - MARGE * 2
    };
    sfRectangleShape_setPosition(button->rectangle, button->pos);
    button->str_text = my_strdup("Increase X");
    button->help_message = my_strdup("Click to increase X");
}

void init_p_pos_y(button_t *button)
{
    engine_t *engine = get_engine();

    button->act_funct = increase_map_y;
    button->pos = (sfVector2f){
        button->rect_size.x + MARGE * 2,
        GET_WINDOW_SIZE(engine).y - button->rect_size.y * 2 - MARGE * 2
    };
    sfRectangleShape_setPosition(button->rectangle, button->pos);
    button->str_text = my_strdup("Increase Y");
    button->help_message = my_strdup("Click to increase Y");
}
