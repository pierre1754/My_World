/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void get_elem(void)
{
    engine_t *engine = get_engine();

    get_pos_button(GET_LISTHEAD(engine)->lh_first);
}
