/*
** EPITECH PROJECT, 2020
** get_on_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void print_map_pos(void)
{
    engine_t *engine = get_engine();
    sfVector2i mouse = sfMouse_getPositionRenderWindow(GET_WINDOW(engine));

    if (engine->event.type == sfEvtMouseButtonPressed) {
        my_put_nbr(mouse.x);
        my_putchar(' ');
        my_put_nbr(mouse.y);
        my_putchar('\n');
    }
}