/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

sfVertexArray *refresh_vertex_line(line_t line, sfVertexArray *array)
{
    sfVertexArray_getVertex(array, 0)->position = line.point1;
    sfVertexArray_getVertex(array, 1)->position = line.point2;
    return array;
}

void refresh_map_line(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        for (int j = 0; j < GET_SET_MY(engine); j++) {
            if (i + 1 != GET_SET_MX(engine)) {
                GET_MAP_LINES(engine)[i][j] = refresh_vertex_line((line_t){
                    GET_MAP_2D(engine)[i][j],
                    GET_MAP_2D(engine)[i + 1][j]
                }, GET_MAP_LINES(engine)[i][j]);
            }
            if (j + 1 != GET_SET_MY(engine)) {
                GET_MAP_LINES(engine)[i][j] = refresh_vertex_line((line_t){
                    GET_MAP_2D(engine)[i][j],
                    GET_MAP_2D(engine)[i][j + 1]
                }, GET_MAP_LINES(engine)[i][j]);
            }
        }
    }
}
