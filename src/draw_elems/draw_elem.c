/*
** EPITECH PROJECT, 2020
** draw_all.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void draw_elem(void)
{
    engine_t *engine = get_engine();

    sfRenderWindow_clear(GET_WINDOW(engine), sfBlack);
    draw_map();
    if (GET_DRAW_BUTTON(engine)) {
        if (GET_SET_MODE(engine) == texture)
            set_tex_button();
        else
            reset_tex_button();
        draw_button(GET_LISTHEAD(engine)->lh_first, GET_WINDOW(engine));
        draw_text(GET_LISTHEAD(engine)->lh_first, GET_WINDOW(engine));
    }
    draw_help();
    sfRenderWindow_display(GET_WINDOW(engine));
}
