/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void save_map(void)
{
    engine_t *engine = get_engine();
    static int map_nbr = 1;
    char *link = my_strndup("asset/map/", my_strlen("my_map") + SIZE_SAVE_MAP +
    my_strlen("asset/map/"));
    char *map = my_strndup("my_map", my_strlen("my_map") + SIZE_SAVE_MAP);
    char *nbr = my_array_nbr(map_nbr, SIZE_SAVE_MAP);
    char *path = my_strcat(link, my_strcat(map, nbr));

    printf("%s\n", path);
    map_nbr++;
}
