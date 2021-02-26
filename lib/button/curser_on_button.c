/*
** EPITECH PROJECT, 2020
** libbutton.c
** File description:
** 25/02/2021
*/

#include "button.h"

static bool if_collision(buttons_t *temp, sfVector2i mouse,
sfVector2f size_rect)
{
    bool x = temp->pos.x < mouse.x && mouse.x < (temp->pos.x + size_rect.x);
    bool y = temp->pos.y < mouse.y && mouse.y < (temp->pos.y + size_rect.y);

    return (x && y);
}

void curser_on_button(buttons_t *button_head, sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f size_rect = {0};
    buttons_t *temp = NULL;

    LIST_HEAD(, buttons_s) buttons;
    buttons.lh_first = button_head;
    LIST_FOREACH(temp, &buttons, entries) {
        size_rect = sfRectangleShape_getSize(temp->rectangle);
        if (if_collision(temp, mouse, size_rect)) {
            sfRectangleShape_setOutlineColor(temp->rectangle,
            sfColor_modulate(sfRectangleShape_getFillColor(temp->rectangle),
            sfColor_fromRGB(128, 0, 0)));
        }
        else {
            sfRectangleShape_setOutlineColor(temp->rectangle, sfRed);
        }
    }
}
