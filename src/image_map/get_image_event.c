/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void get_arrow(sfEvent event, image_map_t *map, time_elapsed_t *time)
{
    sfVector2f pos = sfSprite_getPosition(map->sprite);

    switch (event.key.code) {
    case sfKeyRight:
        pos.x += time->time_elapsed * 1000;
        break;
    case sfKeyLeft:
        pos.x -= time->time_elapsed * 1000;
        break;
    case sfKeyDown:
        pos.y += time->time_elapsed * 1000;
        break;
    case sfKeyUp:
        pos.y -= time->time_elapsed * 1000;
        break;
    default:
        break;
    }
    sfSprite_setPosition(map->sprite, pos);
}

void get_image_evt(sfRenderWindow *window, sfEvent event, image_map_t *map,
time_elapsed_t *time)
{
    float all_scale = sfSprite_getScale(map->sprite).x;

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseWheelScrolled &&
    event.mouseWheelScroll.delta < 0 && all_scale > 0)
        all_scale -= time->time_elapsed * 50;
    else if (event.type == sfEvtMouseWheelScrolled &&
    event.mouseWheelScroll.delta > 0)
        all_scale += time->time_elapsed * 50;
    sfSprite_setScale(map->sprite, (sfVector2f){all_scale, all_scale});
    get_arrow(event, map, time);
}
