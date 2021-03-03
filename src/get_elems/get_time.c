/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void get_time(void)
{
    engine_t *engine = get_engine();

    GET_ELAPSED(engine) = sfTime_asSeconds(sfClock_restart(GET_CLOCK(engine)));
}