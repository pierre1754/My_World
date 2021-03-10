/*
** EPITECH PROJECT, 2020
** get_vertex.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

sfColor **color_dup_2d(sfColor **src)
{
    engine_t *engine = get_engine();
    sfColor **cp_src = malloc(sizeof(sfColor *) * (GET_SET_MX(engine) + 1));

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        cp_src[i] = malloc(sizeof(sfColor) * (GET_SET_MY(engine) + 1));
        if (src[i] != NULL)
            for (int j = 0; j < GET_SET_MY(engine); j++)
                cp_src[i][j] = src[i][j];
        else {
            for (int j = 0; j < GET_SET_MY(engine); j++)
                cp_src[i][j] = sfWhite;
        }
    }
    cp_src[GET_SET_MX(engine)] = NULL;
    return cp_src;
}

sfTexture ***texture_dup_2d(sfTexture ***src)
{
    engine_t *engine = get_engine();
    sfTexture ***cp_src = malloc(sizeof(sfTexture **) * (GET_SET_MX(engine) + 1));

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        cp_src[i] = malloc(sizeof(sfTexture *) * (GET_SET_MY(engine) + 2));
        if (src[i] != NULL)
            for (int j = 0; j < GET_SET_MY(engine); j++)
                cp_src[i][j] = engine->render->grass;
        else {
            for (int j = 0; j < GET_SET_MY(engine); j++) {
                cp_src[i][j] = engine->render->grass;
            }
        }
    }
    cp_src[GET_SET_MX(engine)] = NULL;
    return cp_src;
}
