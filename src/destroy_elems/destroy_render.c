/*
** EPITECH PROJECT, 2020
** draw_all.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void destroy_render(void)
{
    engine_t *engine = get_engine();

    sfTexture_destroy(engine->render->dirt);
    sfTexture_destroy(engine->render->grass);
    sfTexture_destroy(engine->render->sand);
    free(engine->render);
}
