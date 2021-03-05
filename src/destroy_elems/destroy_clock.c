/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void destroy_clock(void)
{
    engine_t *engine = get_engine();

    sfClock_destroy(engine->time->clock);
    free(engine->time);
}
