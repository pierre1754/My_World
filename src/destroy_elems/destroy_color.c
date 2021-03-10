/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void destroy_color_2d(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine); i++)
        free(GET_COLOR_2D(engine)[i]);
    free(GET_COLOR_2D(engine));
}

void destroy_texture_2d(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < GET_SET_MX(engine); i++)
        free(GET_TEX_2D(engine)[i]);
    free(GET_TEX_2D(engine));
}
