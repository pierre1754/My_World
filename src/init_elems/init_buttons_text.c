/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

static const void (*ptr_func[but_nbr])(buttons_t *) = {
    init_plus_x,
    init_minus_x,
    init_plus_y,
    init_minus_y,
    init_plus_zoom,
    init_minus_zoom,
    init_cart_mode,
    init_color_mode
};

void init_text_obj(void)
{
    engine_t *engine = get_engine();
    buttons_t *temp = NULL;
    int id_but = 0;

    for (int i = 0; i < but_nbr; i++) {
        temp = get_new_button();

        ptr_func[i](temp);
        LIST_INSERT_HEAD(GET_LISTHEAD(engine), temp, entries);
        id_but++;
    }
}
