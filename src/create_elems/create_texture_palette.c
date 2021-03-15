/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void create_texture_palette(void)
{
    engine_t *engine = get_engine();

    engine->texture_palette = malloc(sizeof(sfTexture *) * tex_nbr);

    engine->texture_palette[dirt] = sfTexture_createFromFile("asset/dirt.png", NULL);
    engine->texture_palette[grass] = sfTexture_createFromFile("asset/grass.png", NULL);
    engine->texture_palette[sand] = sfTexture_createFromFile("asset/sand.png", NULL);
    engine->texture_palette[ice] = sfTexture_createFromFile("asset/ice.png", NULL);
    engine->texture_palette[netherrack] = sfTexture_createFromFile("asset/netherrack.png", NULL);
    engine->texture_palette[stone] = sfTexture_createFromFile("asset/stone.png", NULL);
    engine->texture_palette[wool] = sfTexture_createFromFile("asset/wool.png", NULL);
    engine->texture_palette[planks] = sfTexture_createFromFile("asset/planks.png", NULL);
    engine->texture_palette[bedrock] = sfTexture_createFromFile("asset/bedrock.png", NULL);
}
