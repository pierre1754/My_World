/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

sfVertexArray *create_vertex_color(square_t quad, sfVertexArray *array, int i,
int j)
{
    engine_t *engine = get_engine();
    sfVertex vertex1 = {.position = quad.point1, .color = get_color(
    GET_MAP_3D(engine), i, j)};
    sfVertex vertex2 = {.position = quad.point2, .color = get_color(
    GET_MAP_3D(engine), i, j + 1)};
    sfVertex vertex3 = {.position = quad.point3, .color = get_color(
    GET_MAP_3D(engine), i + 1, j + 1)};
    sfVertex vertex4 = {.position = quad.point4, .color = get_color(
    GET_MAP_3D(engine), i + 1, j)};

    sfVertexArray_append(array, vertex1);
    sfVertexArray_append(array, vertex2);
    sfVertexArray_append(array, vertex3);
    sfVertexArray_append(array, vertex4);
    sfVertexArray_setPrimitiveType(array, sfQuads);
    return array;
}

sfVertexArray *create_vertex_tex(square_t quad, sfVertexArray *array)
{
    sfVertex vertex1 = {.position = quad.point1, .color = sfWhite, .texCoords =
    (sfVector2f){0, 0}};
    sfVertex vertex2 = {.position = quad.point2, .color = sfWhite, .texCoords =
    (sfVector2f){0, 320}};
    sfVertex vertex3 = {.position = quad.point3, .color = sfWhite, .texCoords =
    (sfVector2f){320, 320}};
    sfVertex vertex4 = {.position = quad.point4, .color = sfWhite, .texCoords =
    (sfVector2f){320, 0}};

    sfVertexArray_append(array, vertex1);
    sfVertexArray_append(array, vertex2);
    sfVertexArray_append(array, vertex3);
    sfVertexArray_append(array, vertex4);
    sfVertexArray_setPrimitiveType(array, sfQuads);
    return array;
}

sfVertexArray *create_vertex_line(line_t line, sfVertexArray *array)
{
    sfVertex vertex1 = {.position = line.point1, .color = sfGreen};
    sfVertex vertex2 = {.position = line.point2, .color = sfGreen};

    sfVertexArray_append(array, vertex1);
    sfVertexArray_append(array, vertex2);
    sfVertexArray_setPrimitiveType(array, sfLinesStrip);
    return array;
}
