/*
** EPITECH PROJECT, 2020
** libbutton.c
** File description:
** 25/02/2021
*/

#include "button.h"

void draw_text(buttons_t *button_head, sfRenderWindow *window)
{
    buttons_t *temp = NULL;

    LIST_HEAD(, buttons_s) buttons;
    buttons.lh_first = button_head;
    LIST_FOREACH(temp, &buttons, entries) {
        sfRenderWindow_drawText(window, temp->text, NULL);
    }
}