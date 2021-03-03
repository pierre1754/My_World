/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void change_draw_mode(void)
{
    engine_t *engine = get_engine();

    GET_SET_MODE(engine) = (GET_SET_MODE(engine) + 1) % 2;
}