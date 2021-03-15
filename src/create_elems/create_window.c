/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void create_window(void)
{
    engine_t *engine = get_engine();
    sfVideoMode mode = {1440, 810, 32};

    engine->window = malloc(sizeof(window_t));
    GET_WINDOW(engine) = sfRenderWindow_create(mode,
                                            "My World",
                                            sfClose,
                                            NULL);
    sfRenderWindow_setFramerateLimit(GET_WINDOW(engine), 60);
    GET_WINDOW_SIZE(engine) = (sfVector2f) {mode.width, mode.height};
}
