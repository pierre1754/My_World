/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void destroy_ascii_elem(ascii_map_t *map, time_elapsed_t *time,
sfRenderWindow *window)
{
    sfText_destroy(map->text);
    sfFont_destroy(map->font);
    free(map->map);
    free(map);
    sfClock_destroy(time->clock);
    free(time);
    sfRenderWindow_destroy(window);
}
