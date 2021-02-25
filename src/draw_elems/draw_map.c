/*
** EPITECH PROJECT, 2020
** draw_all.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

sfVertexArray *create_vertex_quad(sfVector2f *point1, sfVector2f *point2,
sfVector2f *point3, sfVector2f *point4)
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

void draw_2d_map(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine) - 1; i++)
        for (int j = 0; j < GET_SET_MY(engine) - 1; j++)
            sfRenderWindow_drawVertexArray(GET_WINDOW(engine),
            GET_MAP_VER(engine)[i][j], NULL);
}
