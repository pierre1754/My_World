/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

ascii_map_t *create_ascii_map(char *path)
{
    ascii_map_t *map = malloc(sizeof(ascii_map_t));

    map->map = read_map(path);
    if (!map->map)
        return NULL;
    map->font = sfFont_createFromFile("asset/ascii_font.ttf");
    map->text = sfText_create();
    sfText_setString(map->text, map->map);
    sfText_setFillColor(map->text, sfWhite);
    sfText_setCharacterSize(map->text, 20);
    sfText_setFont(map->text, map->font);
    return map;
}

time_elapsed_t *create_time_ascii(void)
{
    time_elapsed_t *time = malloc(sizeof(time_elapsed_t));

    time->clock = sfClock_create();
    time->time_elapsed = 0;
    return time;
}
