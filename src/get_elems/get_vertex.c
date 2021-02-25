/*
** EPITECH PROJECT, 2020
** get_vertex.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

square_t *create_quad(sfVector2f point1, sfVector2f point2, sfVector2f point3,
sfVector2f point4)
{
    square_t *quad = malloc(sizeof(square_t));

    quad->point1 = point1;
    quad->point2 = point2;
    quad->point3 = point3;
    quad->point4 = point4;
    return quad;
}

sfVertexArray *create_vertex_quad(square_t *quad, sfVertexArray *array)
{
    sfVertex vertex1 = {.position = quad->point1, .color = sfGreen};
    sfVertex vertex2 = {.position = quad->point2, .color = sfYellow};
    sfVertex vertex3 = {.position = quad->point3, .color = sfWhite};
    sfVertex vertex4 = {.position = quad->point4, .color = sfYellow};

    sfVertexArray_append(array, vertex1);
    sfVertexArray_append(array, vertex2);
    sfVertexArray_append(array, vertex3);
    sfVertexArray_append(array, vertex4);
    sfVertexArray_setPrimitiveType(array, sfQuads);
    return array;
}
