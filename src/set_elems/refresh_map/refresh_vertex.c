/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void refresh_map_ver(sfVertexArray ***map, sfVector2f **map_vec)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine) - 1; i++) {
        for (int j = 0; j < GET_SET_MY(engine) - 1; j++) {
            map[i][j] = refresh_vertex_quad((square_t){
                map_vec[i][j],
                map_vec[i][j + 1],
                map_vec[i + 1][j + 1],
                map_vec[i + 1][j]
            }, map[i][j]);
        }
    }
}

sfVertexArray *refresh_vertex_quad(square_t quad, sfVertexArray *array)
{
    sfVertexArray_getVertex(array, 0)->color = sfVertexArray_getVertex(array,
    0)->color;
    sfVertexArray_getVertex(array, 1)->color = sfVertexArray_getVertex(array,
    1)->color;
    sfVertexArray_getVertex(array, 2)->color = sfVertexArray_getVertex(array,
    2)->color;
    sfVertexArray_getVertex(array, 3)->color = sfVertexArray_getVertex(array,
    3)->color;
    sfVertexArray_getVertex(array, 0)->position = quad.point1;
    sfVertexArray_getVertex(array, 1)->position = quad.point2;
    sfVertexArray_getVertex(array, 2)->position = quad.point3;
    sfVertexArray_getVertex(array, 3)->position = quad.point4;
    return array;
}
