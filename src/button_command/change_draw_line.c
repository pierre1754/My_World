/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void change_draw_line(void)
{
    engine_t *engine = get_engine();

    GET_SET_LINE(engine) = !GET_SET_LINE(engine);
}