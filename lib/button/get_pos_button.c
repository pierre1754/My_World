/*
** EPITECH PROJECT, 2020
** libbutton.c
** File description:
** 25/02/2021
*/

#include "button.h"

void get_pos_button(buttons_t *button_head)
{
    buttons_t *temp = NULL;

    LIST_HEAD(, buttons_s) buttons;
    buttons.lh_first = button_head;
    LIST_FOREACH(temp, &buttons, entries) {
        temp->pos = sfRectangleShape_getPosition(temp->rectangle);
    }
}
