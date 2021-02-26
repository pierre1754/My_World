/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void set_elem(void)
{
    engine_t *engine = get_engine();
    buttons_t *temp = NULL;

    curser_on_button(GET_LISTHEAD(engine)->lh_first, GET_WINDOW(engine));
    // click_on_button(GET_LISTHEAD(engine)->lh_first, GET_WINDOW(engine));
}
