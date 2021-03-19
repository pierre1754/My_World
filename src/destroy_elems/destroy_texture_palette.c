/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void destroy_texture_palette(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < tex_nbr; i++)
        sfTexture_destroy(engine->texture_palette[i]);
    free(engine->texture_palette);
}
