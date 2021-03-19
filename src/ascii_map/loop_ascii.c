/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

static sfRenderWindow *create_window_size(int x, int y)
{
    unsigned int width = x * 5;
    unsigned int height = y * 5;

    return sfRenderWindow_create(
    (sfVideoMode) {width, height, 32}, "Map Image", sfClose, NULL);
}

int loop_ascii(char *path, int x, int y)
{
    sfRenderWindow *window = create_window_size(x, y);
    ascii_map_t *map = map = create_ascii_map(path, x, y);;
    time_elapsed_t *time = create_time_ascii();
    sfEvent event;

    if (!map->map)
        return 84;
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            get_ascii_evt(window, event, map, time);
        }
        time->time_elapsed = sfTime_asSeconds(sfClock_restart(time->clock));
        draw_ascii_map(window, map);
    }
    destroy_ascii_elem(map, time, window);
    return 0;
}
