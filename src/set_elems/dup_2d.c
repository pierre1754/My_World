/*
** EPITECH PROJECT, 2020
** get_vertex.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

int **intdup_2d(int **src)
{
    engine_t *engine = get_engine();
    int **cp_src = malloc(sizeof(int *) * (GET_SET_MX(engine) + 1));

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        cp_src[i] = malloc(sizeof(int) * (GET_SET_MY(engine) + 1));
        for (int j = 0; j < GET_SET_MY(engine); j++) {
            if (src[i][j] != '\0')
                cp_src[i][j] = src[i][j];
            else {
                cp_src[i][j] = 0;
                cp_src[i][j + 1] = '\0';
            }
        }
    }
    GET_MAP_3D(engine)[GET_SET_MX(engine) - 1] = NULL;
    return cp_src;
}

sfVector2f **vectordup_2d(sfVector2f **src)
{
    engine_t *engine = get_engine();
    sfVector2f **cp_src = malloc(sizeof(sfVector2f *) * (GET_SET_MX(engine)
    + 1));

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        cp_src[i] = malloc(sizeof(sfVector2f) *
        (GET_SET_MY(engine) + 1));
        for (int j = 0; j < GET_SET_MY(engine); j++) {
            cp_src[i][j] = src[i][j];
        }
    }
    GET_MAP_2D(engine)[GET_SET_MX(engine)] = NULL;
    return cp_src;
}

sfVertexArray ***vertexdup_2d(sfVertexArray ***src)
{
    engine_t *engine = get_engine();
    sfVertexArray ***cp_src = malloc(sizeof(sfVertexArray **) * (GET_SET_MX(engine)
    + 1));

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        cp_src[i] = malloc(sizeof(sfVertexArray *) *
        (GET_SET_MY(engine) + 1));
        for (int j = 0; j < GET_SET_MY(engine) - 1; j++) {
            cp_src[i][j] = sfVertexArray_create();
        }
    }
    GET_MAP_VER(engine)[GET_SET_MX(engine)] = NULL;
    return cp_src;
}
