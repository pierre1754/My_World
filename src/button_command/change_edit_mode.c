/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void change_edit_mode(void)
{
    engine_t *engine = get_engine();

    GET_EDIT_MODE(engine) = !GET_EDIT_MODE(engine);
}

void change_line_mode(void)
{
    engine_t *engine = get_engine();

    GET_LINE(engine) = !GET_LINE(engine);
}
