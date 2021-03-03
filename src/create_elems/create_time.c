/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void create_time(void)
{
    engine_t *engine = get_engine();

    engine->time = malloc(sizeof(time_elapsed_t));
    engine->time->clock = sfClock_create();
    engine->time->time_elapsed = 0;
}