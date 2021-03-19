/*
** EPITECH PROJECT, 2020
** get_vertex.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

int *intdup(int *cp_src, int *src)
{
    engine_t *engine = get_engine();

    for (int j = 0; j < GET_SET_MY(engine); j++) {
        if (src[j])
            cp_src[j] = src[j];
        else {
            cp_src[j] = 0;
            cp_src[j + 1] = 0;
        }
    }
    return cp_src;
}

int **intdup_2d(int **src)
{
    engine_t *engine = get_engine();
    int **cp_src = malloc(sizeof(int *) * (GET_SET_MX(engine) + 1));

    memset(cp_src, 0, GET_SET_MX(engine) + 1);
    for (int i = 0; i < GET_SET_MX(engine); i++) {
        cp_src[i] = malloc(sizeof(int) * (GET_SET_MY(engine) + MARGE_MAP));
        memset(cp_src[i], 0, GET_SET_MY(engine) + MARGE_MAP);
        if (src[i] != NULL) {
            cp_src[i] = intdup(cp_src[i], src[i]);
            free(src[i]);
        }
        else {
            for (int j = 0; j < GET_SET_MY(engine); j++)
                cp_src[i][j] = 0;
        }
        cp_src[i][GET_SET_MY(engine)] = 0;
    }
    free(src);
    cp_src[GET_SET_MX(engine)] = NULL;
    return cp_src;
}

sfVector2f **vectordup_2d(sfVector2f **src)
{
    engine_t *engine = get_engine();
    sfVector2f **cp_src = malloc(sizeof(sfVector2f *) * (GET_SET_MX(engine)
    + 1));

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        cp_src[i] = malloc(sizeof(sfVector2f) *
        (GET_SET_MY(engine) + MARGE));
        if (src[i] != NULL) {
            for (int j = 0; j < GET_SET_MY(engine); j++)
                cp_src[i][j] = src[i][j];
            free(src[i]);
        }
        else
            for (int j = 0; j < GET_SET_MY(engine); j++)
                cp_src[i][j] = (sfVector2f){0, 0};
    }
    free(src);
    cp_src[GET_SET_MX(engine)] = NULL;
    return cp_src;
}

sfVertexArray ***vertexdup_2d(void)
{
    engine_t *engine = get_engine();
    sfVertexArray ***cp_src = malloc(sizeof(sfVertexArray **) *
    (GET_SET_MX(engine) + 1));

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        cp_src[i] = malloc(sizeof(sfVertexArray *) *
        (GET_SET_MY(engine) + 1));
        cp_src[i][GET_SET_MY(engine)] = NULL;
        for (int j = 0; j < GET_SET_MY(engine);j++) {
            cp_src[i][j] = sfVertexArray_create();
        }
    }
    cp_src[GET_SET_MX(engine)] = NULL;
    return cp_src;
}

sfVertexArray ***linedup_2d(void)
{
    engine_t *engine = get_engine();
    sfVertexArray ***cp_src = malloc(sizeof(sfVertexArray **) *
    (GET_SET_MX(engine) + 1));

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        cp_src[i] = malloc(sizeof(sfVertexArray *) *
        (GET_SET_MY(engine) + 1));
        cp_src[i][GET_SET_MY(engine)] = NULL;
        for (int j = 0; j < GET_SET_MY(engine);j++) {
            cp_src[i][j] = sfVertexArray_create();
        }
    }
    cp_src[GET_SET_MX(engine)] = NULL;
    return cp_src;
}
