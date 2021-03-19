/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

static unsigned char fill_elem(int *temp)
{
    if (*temp - 255 > 0) {
        *temp -= 255;
        return *temp;
    }
    return 0;
}

static void fill_pixel_array(ascii_map_t *map, char *buffer)
{
    int temp = 0;
    int adv = 0;

    for (; *buffer; buffer++, adv += 4) {
        temp = 3 * (unsigned char)atoi(buffer);
        map->map[adv] = temp % 255;
        map->map[adv + 1] = fill_elem(&temp);
        map->map[adv + 2] = fill_elem(&temp);
        map->map[adv + 3] = 255;
        for (; *buffer != ',' && *buffer != '\n' && *buffer; buffer++);
    }
}

ascii_map_t *create_ascii_map(char *path, int x, int y)
{
    ascii_map_t *map = malloc(sizeof(ascii_map_t));
    char *buf = NULL;

    buf = read_map(path);
    if (!buf)
        return NULL;
    map->map = malloc(sizeof(char) * (x * y * 4 + 1));
    memset(map->map, 0, x * y * 4 + 1);
    fill_pixel_array(map, buf);
    map->image = sfImage_createFromPixels(x, y, (sfUint8 *)map->map);
    map->sprite = sfSprite_create();
    map->tex = sfTexture_createFromImage(map->image, NULL);
    sfSprite_setScale(map->sprite, (sfVector2f){5, 5});
    sfSprite_setTexture(map->sprite, map->tex, sfTrue);
    return map;
}

time_elapsed_t *create_time_ascii(void)
{
    time_elapsed_t *time = malloc(sizeof(time_elapsed_t));

    time->clock = sfClock_create();
    time->time_elapsed = 0;
    return time;
}
