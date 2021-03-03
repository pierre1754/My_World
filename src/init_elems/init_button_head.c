/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void init_button_head(void)
{
    engine_t *engine = get_engine();

    GET_LISTHEAD(engine)->lh_first = NULL;
}
