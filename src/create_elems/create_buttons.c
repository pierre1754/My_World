/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

static void fill_button(engine_t *engine, button_t *button)
{
    button->rectangle = sfRectangleShape_create();
    button->rect_size = (sfVector2f) {150, 75};
    button->pos = (sfVector2f) {0};
    button->text = sfText_create();
    button->str_text = NULL;
    button->help_message = NULL;
    button->color = sfBlue;
    button->act_funct = NULL;
    sfRectangleShape_setSize(button->rectangle,
    button->rect_size);
    sfRectangleShape_setFillColor(button->rectangle,
    button->color);
    sfRectangleShape_setOutlineThickness(
    button->rectangle, -2.f);
    sfRectangleShape_setOutlineColor(button->rectangle,
    sfColor_modulate(button->color, (sfColor) {0, 0, 128, 255}));
    sfText_setFont(button->text, engine->message->font);
    sfText_setColor(button->text, sfWhite);
    sfText_setCharacterSize(button->text, 17);
}

void create_buttons(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < buttons; i++) {
        BUT_AR(engine)[i] = malloc(sizeof(button_t));
        fill_button(engine, BUT_AR(engine)[i]);
    }
}
