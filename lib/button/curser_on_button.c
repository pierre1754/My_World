/*
** EPITECH PROJECT, 2020
** libbutton.c
** File description:
** 25/02/2021
*/

#include "button.h"

bool curser_on_button(button_t *button, sfVector2i mouse_pos,
help_message_t *message)
{
    if (if_collision(button->pos, mouse_pos, button->rect_size)) {
        sfRectangleShape_setOutlineThickness(button->rectangle, -5.f);
        sfText_setString(message->message, button->help_message);
        return 1;
    }
    else sfRectangleShape_setOutlineThickness(button->rectangle, -2.f);
    return 0;
}
