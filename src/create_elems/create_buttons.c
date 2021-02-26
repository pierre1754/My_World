/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void create_buttons(void)
{
    engine_t *engine = get_engine();

    LIST_INIT(GET_LISTHEAD(engine));
}

buttons_t *get_new_button(void)
{
    engine_t *engine = get_engine();
    buttons_t *button = malloc(sizeof(buttons_t));

    button->rectangle = sfRectangleShape_create();
    button->font = sfFont_createFromFile("asset/button_font.ttf");
    button->text = sfText_create();
    button->pos = (sfVector2f){0};
    sfRectangleShape_setFillColor(button->rectangle, sfRed);
    sfRectangleShape_setSize(button->rectangle, (sfVector2f){100, 100});
    sfRectangleShape_setOutlineThickness(button->rectangle, -2.f);
    return button;
}
