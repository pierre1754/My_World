/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void destroy_buttons(void)
{
    engine_t *engine = get_engine();
    buttons_t *button = NULL;
    buttons_t *button_temp = NULL;

    LIST_FOREACH_SAFE(button, GET_LISTHEAD(engine), entries, button_temp) {
        destroy_one_button(button);
    }
}

void destroy_one_button(buttons_t *button)
{
    sfRectangleShape_destroy(button->rectangle);
    sfText_destroy(button->text);
    sfFont_destroy(button->font);
    LIST_REMOVE(button, entries);
    free(button);
}
