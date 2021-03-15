/*
** EPITECH PROJECT, 2020
** libbutton.c
** File description:
** 25/02/2021
*/

#include "button.h"

bool if_collision(sfVector2f pos, sfVector2i mouse_pos, sfVector2f size_rect)
{
    bool x = pos.x < mouse_pos.x && mouse_pos.x < (pos.x + size_rect.x);
    bool y = pos.y < mouse_pos.y && mouse_pos.y < (pos.y + size_rect.y);

    return x && y;
}

void click_on_button(button_t *button, sfVector2i mouse_pos, sfEvent event)
{
    if (if_collision(button->pos, mouse_pos, button->rect_size) &&
        event.type == sfEvtMouseButtonPressed) {
        sfRectangleShape_setFillColor(button->rectangle,
        sfColor_modulate(button->color, sfColor_fromRGB(0, 0, 128)));
        button->act_funct();
    }
    else {
        sfRectangleShape_setFillColor(button->rectangle, button->color);
    }
}
