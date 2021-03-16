/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void init_m_angle_x(button_t *button)
{
    engine_t *engine = get_engine();

    button->act_funct = decrease_angle_x;
    button->pos = (sfVector2f){
        button->rect_size.x * 2 + MARGE * 3,
        GET_WINDOW_SIZE(engine).y - button->rect_size.y - MARGE
    };
    sfRectangleShape_setPosition(button->rectangle, button->pos);
    button->str_text = my_strdup("Decrease angle X");
    button->help_message = my_strdup("Click to Decrease angle X");
}

void init_m_angle_y(button_t *button)
{
    engine_t *engine = get_engine();

    button->act_funct = decrease_angle_y;
    button->pos = (sfVector2f){
        button->rect_size.x * 3 + MARGE * 4,
        GET_WINDOW_SIZE(engine).y - button->rect_size.y - MARGE
    };
    sfRectangleShape_setPosition(button->rectangle, button->pos);
    button->str_text = my_strdup("Decrease angle Y");
    button->help_message = my_strdup("Click to decrease angle Y");
}

void init_p_angle_x(button_t *button)
{
    engine_t *engine = get_engine();

    button->act_funct = increase_angle_x;
    button->pos = (sfVector2f){
        button->rect_size.x * 2 + MARGE * 3,
        GET_WINDOW_SIZE(engine).y - button->rect_size.y * 2 - MARGE * 2
    };
    sfRectangleShape_setPosition(button->rectangle, button->pos);
    button->str_text = my_strdup("Increase angle X");
    button->help_message = my_strdup("Click to increase angle X");
}

void init_p_angle_y(button_t *button)
{
    engine_t *engine = get_engine();

    button->act_funct = increase_angle_y;
    button->pos = (sfVector2f){
        button->rect_size.x * 3 + MARGE * 4,
        GET_WINDOW_SIZE(engine).y - button->rect_size.y * 2 - MARGE * 2
    };
    sfRectangleShape_setPosition(button->rectangle, button->pos);
    button->str_text = my_strdup("Increase angle Y");
    button->help_message = my_strdup("Click to increase angle Y");
}
