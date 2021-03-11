/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void create_map(char *file)
{
    engine_t *engine = get_engine();

    engine->map = malloc(sizeof(map_t));
    if (file) {
        GET_SET_LOD(engine) = 1;
        get_size_map(file);
        file_to_map(my_str_to_line_array(file));
    } else {
        GET_SET_LOD(engine) = 0;
        GET_MAP_3D(engine) = create_map_3d();
    }
    GET_MAP_3D_BASE(engine) = create_map_3d();
    GET_MAP_2D(engine) = create_map_2d();
    GET_MAP_2D_BASE(engine) = create_map_2d();
    GET_MAP_COLOR(engine) = create_map_ver();
    GET_MAP_TEX(engine) = create_map_ver();
    GET_MAP_LINES(engine) = create_map_ver();
    GET_MAP_ORIGIN(engine) = create_map_ver();
    GET_COLOR_2D(engine) = create_color_2d();
    GET_TEX_2D(engine) = create_texture_2d();
}

int **create_map_3d(void)
{
    engine_t *engine = get_engine();
    int **map = malloc(sizeof(int *) * (GET_SET_MX(engine) + 1));

    memset(map, 0, GET_SET_MX(engine) + 1);
    for (int i = 0; i < GET_SET_MX(engine); i++) {
        map[i] = malloc(sizeof(int) * (GET_SET_MY(engine) + MARGE_MAP));
        memset(map[i], 0, GET_SET_MY(engine) + MARGE_MAP);
    }
    map[GET_SET_MX(engine)] = NULL;
    return map;
}

sfVector2f **create_map_2d(void)
{
    engine_t *engine = get_engine();
    sfVector2f **map = malloc(sizeof(sfVector2f *) * (GET_SET_MX(engine) + 1));

    for (int i = 0; i < GET_SET_MX(engine); i++)
        map[i] = malloc(sizeof(sfVector2f) *
        (GET_SET_MY(engine) + MARGE_MAP));
    map[GET_SET_MX(engine)] = NULL;
    return map;
}

sfVertexArray ***create_map_ver(void)
{
    engine_t *engine = get_engine();
    sfVertexArray ***map = malloc(sizeof(sfVertexArray **) *
    (GET_SET_MX(engine) + 1));

    for (int i = 0; i < GET_SET_MX(engine); i++) {
        map[i] = malloc(sizeof(sfVertexArray *) * (GET_SET_MY(engine) + 1));
        map[i][GET_SET_MY(engine)] = NULL;
        for (int j = 0; j < GET_SET_MY(engine); j++)
            map[i][j] = sfVertexArray_create();
    }
    map[GET_SET_MX(engine)] = NULL;
    return map;
}
