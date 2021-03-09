/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void init_new_perlin_map_rect(buttons_t *button, sfVector2f rect_size)
{
    button->pos = (sfVector2f){
        rect_size.x + MARGE * 2,
        MARGE
    };
    sfRectangleShape_setPosition(button->rectangle, button->pos);
}

void init_new_perlin_map_text(buttons_t *button, sfVector2f rect_size)
{
    button->str_text = my_strdup("New Perlin Map");
    button->help_message =
    my_strdup("Reset the map and make a new one with the perlin noise");
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

void init_new_perlin_map(buttons_t *button)
{
    sfVector2f rect_size = {0};

    rect_size = sfRectangleShape_getSize(button->rectangle);
    button->act_funct = init_perlin;
    init_new_perlin_map_rect(button, rect_size);
    init_new_perlin_map_text(button, rect_size);
}
