/*
** EPITECH PROJECT, 2020
** libbutton.c
** File description:
** 25/02/2021
*/

#include "button.h"

void draw_help_text(sfText *help_message, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, help_message, NULL);
}
