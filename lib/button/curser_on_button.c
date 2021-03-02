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

void curser_on_button(
    buttons_t *button_head,
    sfRenderWindow *window,
    settings_t *settings
)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f size_rect = {0};
    buttons_t *temp = NULL;

    LIST_HEAD(, buttons_s) buttons;
    buttons.lh_first = button_head;
    LIST_FOREACH(temp, &buttons, entries) {
        size_rect = sfRectangleShape_getSize(temp->rectangle);
        if (if_collision(temp, mouse, size_rect)) {
            sfRectangleShape_setOutlineThickness(temp->rectangle, -5.f);
            settings->on_button = 1;
        }
        else {
            sfRectangleShape_setOutlineThickness(temp->rectangle, -2.f);
            settings->on_button = 0;
        }
    }
}
