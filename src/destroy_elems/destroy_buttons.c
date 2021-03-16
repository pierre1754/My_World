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

    for (int i = 0; i < buttons; i++) {
        sfRectangleShape_destroy(BUT_AR(engine)[i]->rectangle);
        sfText_destroy(BUT_AR(engine)[i]->text);
        free(BUT_AR(engine)[i]->help_message);
        free(BUT_AR(engine)[i]->str_text);
        free(BUT_AR(engine)[i]);
    }
}
