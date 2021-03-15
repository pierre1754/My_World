/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void get_arrow(sfEvent event, ascii_map_t *map)
{
    sfVector2f pos = sfText_getPosition(map->text);

    switch (event.key.code) {
    case sfKeyRight:
        pos.x -= 20;
        break;
    case sfKeyLeft:
        pos.x += 20;
        break;
    case sfKeyDown:
        pos.y += 20;
        break;
    case sfKeyUp:
        pos.y -= 20;
        break;
    default:
        break;
    }
    sfText_setPosition(map->text, pos);
}

void get_ascii_evt(sfRenderWindow *window, sfEvent event, ascii_map_t *map)
{
    unsigned int font = sfText_getCharacterSize(map->text);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseWheelScrolled &&
    event.mouseWheelScroll.delta < 0 && font > 0)
        sfText_setCharacterSize(map->text, font - 1);
    else if (event.type == sfEvtMouseWheelScrolled &&
    event.mouseWheelScroll.delta > 0)
        sfText_setCharacterSize(map->text, font + 1);
    get_arrow(event, map);
}
