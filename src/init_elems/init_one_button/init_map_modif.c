/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void init_palette_color(button_t *button)
{
    engine_t *engine = get_engine();

    button->act_funct = change_color_map;
    button->pos = (sfVector2f){
        GET_WINDOW_SIZE(engine).x - MARGE - button->rect_size.x,
        MARGE
    };
    sfRectangleShape_setPosition(button->rectangle, button->pos);
    button->str_text = my_strdup("Change Color");
    button->help_message = my_strdup("Click to change the actual color");
}

void init_new_map(button_t *button)
{
    button->act_funct = init_map;
    button->pos = (sfVector2f){
        MARGE,
        MARGE
    };
    sfRectangleShape_setPosition(button->rectangle, button->pos);
    button->str_text = my_strdup("New Map");
    button->help_message = my_strdup("Reset the map");
}

void init_new_perlin_map(button_t *button)
{
    button->act_funct = init_perlin;
    button->pos = (sfVector2f){
        button->rect_size.x + MARGE * 2,
        MARGE
    };
    sfRectangleShape_setPosition(button->rectangle, button->pos);
    button->str_text = my_strdup("New Perlin Map");
    button->help_message =
    my_strdup("Reset the map and make a new one with the perlin noise");
}
