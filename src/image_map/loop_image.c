/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

static sfRenderWindow *create_window_size(int x, int y)
{
    unsigned int width = (x * 5) % 1920;
    unsigned int height = (y * 5) % 1080;

    return sfRenderWindow_create(
    (sfVideoMode) {width, height, 32}, "Map Image", sfClose, NULL);
}

int loop_image(char *path)
{
    sfRenderWindow *window = NULL;
    image_map_t *map = create_image_map(path);
    time_elapsed_t *time = create_time_image();
    sfEvent event;

    if (!map)
        return 84;
    window = create_window_size(map->x, map->y);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            get_image_evt(window, event, map, time);
        }
        time->time_elapsed = sfTime_asSeconds(sfClock_restart(time->clock));
        draw_image_map(window, map);
    }
    destroy_image_elem(map, time, window);
    return 0;
}
