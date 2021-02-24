/*
** EPITECH PROJECT, 2020
** Base
** File description:
** main
*/

#include "bs_my_world.h"
#include <stdlib.h>
#include <time.h>

sfRenderWindow *create_my_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "game",
    sfVideoMode_isValid(video_mode) ? sfDefaultStyle : sfClose, NULL);
    return window;
}

void event_loop(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

int **create_map(int max_x, int max_y)
{
    int **map = malloc(sizeof(int *) * (max_x + 1));

    for (int i = 0; i < max_x; i++) {
        map[i] = malloc(sizeof(int) * (max_y + 1));
        for (int j = 0; j < max_y; j++) {
            if (j - 1 == max_y || i - 1 == max_x)
                 map[i][j] = 0;
            else
                map[i][j] = rand() % 3 - 1;
        }
        map[i][max_y] = '\0';
    }
    map[max_x] = NULL;
    return map;
}

sfVector2f project_iso_point(int x, int y, int z)
{
    sfVector2f point_2d = {0, 0};
    float angle_x = 45 * 3.14 / 180;
    float angle_y = 45 * 3.14 / 180;

    point_2d.x = (cos(angle_x) * x - cos(angle_x) * y) * 100 + WINDOW_SIZE_X / 2;
    point_2d.y = (sin(angle_y) * y + sin(angle_y) * x - z) * 100;
    return point_2d;
}

sfVector2f **create_2d_map(int **map)
{
    sfVector2f **map_2d = malloc(sizeof(sfVector2f *) * (6 + 1));

    for (int i = 0; i < MAX_X; i++) {
        map_2d[i] = malloc(sizeof(sfVector2f) * (6 + 1));
        for (int j = 0; j < MAX_Y; j++)
            map_2d[i][j] = project_iso_point(i, j, map[i][j]);
    }
    return map_2d;
}

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2, sfVector2f *point3, sfVector2f *point4)
{
    sfVertexArray *array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfGreen};
    sfVertex vertex2 = {.position = *point2, .color = sfYellow};
    sfVertex vertex3 = {.position = *point3, .color = sfWhite};
    sfVertex vertex4 = {.position = *point4, .color = sfYellow};

    sfVertexArray_append(array, vertex1);
    sfVertexArray_append(array, vertex2);
    sfVertexArray_append(array, vertex3);
    sfVertexArray_append(array, vertex4);
    sfVertexArray_setPrimitiveType(array, sfQuads);
    return array;
}

void draw_2d_map(sfRenderWindow *window, sfVector2f **map)
{
    sfRenderWindow_clear(window, sfBlack);
    for (int i = 0; i < MAX_X - 1; i++) {
        for (int j = 0; j < MAX_Y - 1; j++) {
                sfRenderWindow_drawVertexArray(window, create_line(&map[i][j], &map[i][j + 1], &map[i + 1][j + 1], &map[i + 1][j]), NULL);
        }
    }
	sfRenderWindow_display(window);
}

int main(void)
{
    sfEvent event;
    sfRenderWindow *window = create_my_window(WINDOW_SIZE_X, WINDOW_SIZE_Y);
    int **map = create_map(MAX_X, MAX_Y);
    sfVector2f **map_2d = create_2d_map(map);

    srand(time(NULL));
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        event_loop(window, event);
        draw_2d_map(window, map_2d);
    }
    return 0;
}
