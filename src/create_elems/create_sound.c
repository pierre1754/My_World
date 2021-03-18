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
    engine->sounds[dirt] = sfSoundBuffer_createFromFile("asset/sounds/grass.ogg");
    engine->sounds[grass] = sfSoundBuffer_createFromFile("asset/sounds/grass.ogg");
    engine->sounds[sand] = sfSoundBuffer_createFromFile("asset/sounds/sand.ogg");
    engine->sounds[ice] = sfSoundBuffer_createFromFile("asset/sounds/ice.ogg");
    engine->sounds[netherrack] = sfSoundBuffer_createFromFile("asset/sounds/netherrack.ogg");
    engine->sounds[stone] = sfSoundBuffer_createFromFile("asset/sounds/stone.ogg");
    engine->sounds[snow] = sfSoundBuffer_createFromFile("asset/sounds/snow.ogg");
    engine->sounds[planks] = sfSoundBuffer_createFromFile("asset/sounds/wood.ogg");
    engine->sounds[bedrock] = sfSoundBuffer_createFromFile("asset/sounds/stone.ogg");
    engine->play = sfSound_create();
}
