/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void destroy_image_elem(image_map_t *map, time_elapsed_t *time,
sfRenderWindow *window)
{
    sfImage_saveToFile(map->image, "asset/image_map/image.png");
    sfSprite_destroy(map->sprite);
    sfTexture_destroy(map->tex);
    sfImage_destroy(map->image);
    free(map->map);
    free(map);
    sfClock_destroy(time->clock);
    free(time);
    sfRenderWindow_destroy(window);
}
