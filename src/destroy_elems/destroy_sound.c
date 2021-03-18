/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void destroy_sound(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < tex_nbr; i++)
        sfSoundBuffer_destroy(engine->sounds[i]);
    sfSound_destroy(engine->play);
}
