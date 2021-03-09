/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

sfColor **create_color_2d(void)
{
    engine_t *engine = get_engine();
    sfColor **map = malloc(sizeof(sfColor *) * (GET_SET_MX(engine) + 1));

    for (int i = 0; i < GET_SET_MX(engine); i++)
        map[i] = malloc(sizeof(sfColor) * (GET_SET_MY(engine) + 1));
    map[GET_SET_MX(engine)] = NULL;
    return map;
}

sfTexture ***create_texture_2d(void)
{
    engine_t *engine = get_engine();
    sfTexture ***map = malloc(sizeof(sfTexture **) * (GET_SET_MX(engine) + 1));

    for (int i = 0; i < GET_SET_MX(engine); i++)
        map[i] = malloc(sizeof(sfTexture *) * (GET_SET_MY(engine) + 1));
    map[GET_SET_MX(engine)] = NULL;
    return map;
}
