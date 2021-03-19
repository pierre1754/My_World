/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void draw_ascii_map(sfRenderWindow *window, ascii_map_t *map)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, map->sprite, NULL);
    sfRenderWindow_display(window);
}
