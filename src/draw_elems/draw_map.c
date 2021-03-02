/*
** EPITECH PROJECT, 2020
** draw_all.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void draw_2d_map(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine); i++)
        for (int j = 0; j < GET_SET_MY(engine); j++) {
            if (i + 1 != GET_SET_MX(engine) && j + 1 != GET_SET_MY(engine))
                sfRenderWindow_drawVertexArray(GET_WINDOW(engine),
                GET_MAP_VER(engine)[i][j], NULL);
            sfRenderWindow_drawVertexArray(GET_WINDOW(engine),
            GET_MAP_LINES(engine)[i][j], NULL);
        }
}
