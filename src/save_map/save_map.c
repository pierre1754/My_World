/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void write_map(char *path)
{
    engine_t *engine = get_engine();
    // FILE *file = fopen(path, "w");
    // char *nbr = NULL;

    // for (int i = 0; i < GET_SET_MX(engine); i++) {
    //     for (int j = 0; j < GET_SET_MY(engine); j++) {
    //         nbr =
    //         fwrite( sizeof(int), file)
    //     }
    // }
}

void save_map(void)
{
    static int map_nbr = 1;
    char *link = malloc(sizeof(char) * (my_strlen("my_map") + SIZE_SAVE_MAP +
    my_strlen("asset/map/") + 2));
    char *map = malloc(sizeof(char) * (my_strlen("my_map") + SIZE_SAVE_MAP + 2));
    char *nbr = my_array_nbr(map_nbr, SIZE_SAVE_MAP);
    char *path = NULL;

    memset(link, '\0', my_strlen("my_map") + SIZE_SAVE_MAP +
    my_strlen("asset/map/") + 1);
    memset(map, '\0', my_strlen("my_map") + SIZE_SAVE_MAP + 1);
    link = my_strcpy(link, "asset/map/");
    map = my_strcpy(map, "my_map");
    path = my_strcat(link, my_strcat(map, nbr));

    free(nbr);
    free(map);
    free(link);
    map_nbr++;
}
