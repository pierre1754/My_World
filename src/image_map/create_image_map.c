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

static void fill_pixel_array(image_map_t *map, char *buffer)
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

static void calc_xy(image_map_t *map, char *buffer)
{
    bool act = 1;

    map->y = 0;
    map->x = 1;
    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] == ',' && act)
            map->x++;
        if (buffer[i] == '\n')
            act = 0;
        if (buffer[i] == '\n')
            map->y++;
    }
}

image_map_t *create_image_map(char *path)
{
    image_map_t *map = malloc(sizeof(image_map_t));
    char *buf = NULL;

    buf = read_map(path);
    calc_xy(map, buf);
    if (!buf)
        return NULL;
    map->map = malloc(sizeof(char) * (map->x * map->y * 4 + 1));
    memset(map->map, 0, map->x * map->y * 4 + 1);
    fill_pixel_array(map, buf);
    map->image = sfImage_createFromPixels(map->x, map->y, (sfUint8 *)map->map);
    map->sprite = sfSprite_create();
    map->tex = sfTexture_createFromImage(map->image, NULL);
    sfSprite_setScale(map->sprite, (sfVector2f){5, 5});
    sfSprite_setTexture(map->sprite, map->tex, sfTrue);
    return map;
}

time_elapsed_t *create_time_image(void)
{
    time_elapsed_t *time = malloc(sizeof(time_elapsed_t));

    time->clock = sfClock_create();
    time->time_elapsed = 0;
    return time;
}
