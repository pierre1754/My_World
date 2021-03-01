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
    buttons_t *temp = NULL;

    temp = get_new_button();
    LIST_INSERT_HEAD(GET_LISTHEAD(engine), temp, entries);
}
