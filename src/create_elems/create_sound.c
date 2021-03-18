/*
** EPITECH PROJECT, 2020
** get_on_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void create_sound(void)
{
    engine_t *engine = get_engine();

    engine->sounds = malloc(sizeof(sfSound *) * tex_nbr);
    engine->sounds[dirt] = sfSoundBuffer_createFromFile(GRASS_SOUND);
    engine->sounds[grass] = sfSoundBuffer_createFromFile(GRASS_SOUND);
    engine->sounds[sand] = sfSoundBuffer_createFromFile(SAND_SOUND);
    engine->sounds[ice] = sfSoundBuffer_createFromFile(ICE_SOUND);
    engine->sounds[netherrack] = sfSoundBuffer_createFromFile(NETHER_SOUND);
    engine->sounds[stone] = sfSoundBuffer_createFromFile(STONE_SOUND);
    engine->sounds[snow] = sfSoundBuffer_createFromFile(SNOW_SOUND);
    engine->sounds[planks] = sfSoundBuffer_createFromFile(WOOD_SOUND);
    engine->sounds[bedrock] = sfSoundBuffer_createFromFile(STONE_SOUND);
    engine->play = sfSound_create();
}
