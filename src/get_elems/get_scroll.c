/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

static void get_scroll_minus(void)
{
    engine_t *engine = get_engine();

    if (engine->event.type == sfEvtMouseWheelScrolled &&
    engine->event.mouseWheelScroll.delta > 0)
        if (GET_SET_RAD(engine) - 10 > 0)
            GET_SET_RAD(engine) -= 10;
}

void get_scroll(void)
{
    engine_t *engine = get_engine();

    if (engine->event.type == sfEvtMouseWheelScrolled &&
    engine->event.mouseWheelScroll.delta < 0)
        GET_SET_RAD(engine) += 10;
    else
        get_scroll_minus();
}
