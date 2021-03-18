/*
** EPITECH PROJECT, 2020
** get_on_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void play_sound(void)
{
    engine_t *engine = get_engine();

    sfSound_setBuffer(engine->play, engine->sounds[GET_COLOR_ID(engine)]);
    sfSound_play(engine->play);
}
