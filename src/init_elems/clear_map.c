/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void clear_map_ver(sfVertexArray ***map)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine) - 1; i++) {
        for (int j = 0; j < GET_SET_MY(engine) - 1; j++) {
            sfVertexArray_clear(map[i][j]);
        }
    }
}

void clear_map_lines(sfVertexArray ***map)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        for (int j = 0; j < GET_SET_MY(engine); j++) {
            sfVertexArray_clear(map[i][j]);
        }
    }
}
