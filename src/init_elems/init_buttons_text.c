/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

static void (*ptr_func[but_nbr])(buttons_t *) =
{
    init_plus_x,
    init_minus_x,
    init_plus_y,
    init_minus_y,
    init_cart_mode,
    init_change_mode,
    init_new_map,
    init_angle_plus_x,
    init_angle_minus_x,
    init_angle_plus_y,
    init_angle_minus_y,
    init_new_perlin_map,
    init_color_palette,
    init_edit_mode
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
