/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void init_perlin(void)
{
    engine_t *engine = get_engine();

    init_perlin_map(GET_MAP_3D(engine));
    init_map_int(GET_MAP_3D_BASE(engine));
    calc_map_vec(GET_MAP_2D(engine), GET_MAP_3D(engine));
    calc_map_vec(GET_MAP_2D_BASE(engine), GET_MAP_3D_BASE(engine));
    init_color_2d();
    init_texture_2d();
    init_map_color(GET_MAP_COLOR(engine), GET_MAP_2D(engine));
    init_map_tex(GET_MAP_ORIGIN(engine), GET_MAP_2D_BASE(engine));
    init_map_line();
    recalc_map();
}

void init_perlin_map(int **map)
{
    engine_t *engine = get_engine();
    static long int temp = 1;
    float calc = 0;

    if (GET_SET_LOD(engine)) {
        GET_SET_LOD(engine) = 0;
        return;
    }
    srand((long int)temp);
    GET_SEED(engine) = rand();
    calc = rand() / 10000.f;
    GET_DEPTH(engine) = fmod(calc, 6.f) + 1;
    GET_FREQ(engine) = fmod(calc, 0.1f);
    for (int i = 1; i < GET_SET_MX(engine) - 1; i++) {
        for (int j = 1; j < GET_SET_MY(engine) - 1; j++) {
            map[i][j] = 30 * perlin_noise(i * GET_FREQ(engine),
            j * GET_FREQ(engine), GET_DEPTH(engine), GET_SEED(engine));
        }
    }
    temp++;
}
