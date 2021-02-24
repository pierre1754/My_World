/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_world.h"
#define ANGLE_X_RAD engine->settings->angle_x * 3.14 / 180
#define ANGLE_Y_RAD engine->settings->angle_y * 3.14 / 180

int **create_map_3d(int max_x, int max_y)
{
    int **map_3d = malloc(sizeof(int *) * (max_x + 1));

    for (int i = 0; i < max_x; i++) {
        map_3d[i] = malloc(sizeof(int) * (max_y + 1));
        for (int j = 0; j < max_y; j++)
            map_3d[i][j] = 0;
        map_3d[i][max_y] = '\0';
    }
    map_3d[max_x] = NULL;
    return map_3d;
}

sfVector2f project_iso_point(int x, int y, int z)
{
    engine_t *engine = get_engine();
    sfVector2f point_2d = {0, 0};

    point_2d.x = (cos(ANGLE_X_RAD) * x - cos(ANGLE_X_RAD) * y) * engine->settings->zoom + engine->settings->max_x / 2;
    point_2d.y = (sin(ANGLE_Y_RAD) * y + sin(ANGLE_Y_RAD) * x - z) * engine->settings->zoom;
    return point_2d;
}

sfVector2f **create_map_2d(int **map_2d)
{
    sfVector2f **map_2d = malloc(sizeof(sfVector2f *) * (6 + 1));

    for (int i = 0; i < 6; i++) {
        map_2d[i] = malloc(sizeof(sfVector2f) * (6 + 1));
        for (int j = 0; j < 5; j++)
            map_2d[i][j] = project_iso_point(i, j, map_2d[i][j]);
    }
    return map_2d;
}
