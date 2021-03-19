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
    engine->texture_palette[dirt] = sfTexture_createFromFile(DIRT, NULL);
    engine->texture_palette[grass] = sfTexture_createFromFile(GRASS, NULL);
    engine->texture_palette[sand] = sfTexture_createFromFile(SAND, NULL);
    engine->texture_palette[ice] = sfTexture_createFromFile(ICE, NULL);
    engine->texture_palette[netherrack] = sfTexture_createFromFile(NETHERRACK,
    NULL);
    engine->texture_palette[stone] = sfTexture_createFromFile(STONE, NULL);
    engine->texture_palette[snow] = sfTexture_createFromFile(SNOW, NULL);
    engine->texture_palette[planks] = sfTexture_createFromFile(PLANKS, NULL);
    engine->texture_palette[bedrock] = sfTexture_createFromFile(BEDROCK, NULL);
}
