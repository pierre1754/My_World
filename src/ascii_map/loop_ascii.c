/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

int loop_ascii(char *path)
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode) {800, 600, 32},
    "ASCII Map", sfClose, NULL);
    ascii_map_t *map = create_ascii_map(path);
    time_elapsed_t *time = create_time_ascii();
    sfEvent event;

    sfRenderWindow_setFramerateLimit(window, 60);
    if (!map->map)
        return 84;
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
