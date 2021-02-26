/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void get_event(void)
{
    engine_t *engine = get_engine();

    curser_on_button(GET_LISTHEAD(engine)->lh_first, GET_WINDOW(engine));
    click_on_button(GET_LISTHEAD(engine)->lh_first,
                    GET_WINDOW(engine),
                    engine->event);
}
