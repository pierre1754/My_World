/*
** EPITECH PROJECT, 2020
** libbutton.c
** File description:
** 25/02/2021
*/

#include "button.h"

void draw_button(button_t *button, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, button->rectangle, NULL);
    sfRenderWindow_drawText(window, button->text, NULL);
}
