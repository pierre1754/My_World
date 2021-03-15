/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

char *get_map_nbr(void)
{
    static int map_nbr = 1;
    char *buffer = malloc(sizeof(char) * (SIZE_SAVE_MAP + 1));
    char *map = malloc(sizeof(char) * (my_strlen("asset/map/my_map") +
    SIZE_SAVE_MAP + 1));
    char *nbr = my_array_nbr(map_nbr, SIZE_SAVE_MAP, buffer);
    char *path = NULL;

    buffer[SIZE_SAVE_MAP] = '\0';
    memset(map, '\0', my_strlen("asset/map/my_map") + SIZE_SAVE_MAP);
    map = my_strcpy(map, "asset/map/my_map");
    path = my_strdup(my_strcat(map, nbr));
    free(buffer);
    free(map);
    map_nbr++;
    return path;
}

void write_map(char *path)
{
    engine_t *engine = get_engine();
    FILE *file = fopen(path, "w");
    char *buffer = malloc(sizeof(char) * (SIZE_SAVE_MAP + 1));
    char *digit = NULL;

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        for (int j = 0; j < GET_SET_MY(engine); j++) {
            memset(buffer, '\0', SIZE_SAVE_MAP);
            if (j != 0)
                fwrite(",", sizeof(char), my_strlen(","), file);
            digit = my_array_nbr(GET_MAP_3D(engine)[i][j],
            SIZE_SAVE_MAP, buffer);
            fwrite(digit, sizeof(char), my_strlen(digit), file);
        }
        fwrite(";\n", sizeof(char), my_strlen(";\n"), file);
    }
    fclose(file);
    free(buffer);
}

void save_map(void)
{
    char *path = get_map_nbr();

    write_map(path);
}
