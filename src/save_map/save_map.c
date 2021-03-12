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
    static int map_nbr = 0;
    char *path = my_strndup("my_map", my_strlen("my_map") + 10);

    printf("%s, %d\n", my_array_nbr(map_nbr, 10), map_nbr);
    // fopen()
    map_nbr++;
}
