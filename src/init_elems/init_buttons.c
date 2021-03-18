/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

static void (*ptr_func[buttons])(button_t *) =
{
    init_p_angle_x,
    init_m_angle_x,
    init_p_angle_y,
    init_m_angle_y,
    init_p_pos_x,
    init_m_pos_x,
    init_p_pos_y,
    init_m_pos_y,
    init_new_map,
    init_new_perlin_map,
    init_change_mode,
    init_map_mode,
    init_palette_color,
    init_edit_mode,
    init_line_mode
};

void init_buttons(void)
{
    engine_t *engine = get_engine();

    for (int i = 0; i < buttons; i++) {
        ptr_func[i](BUT_AR(engine)[i]);
        sfText_setString(BUT_AR(engine)[i]->text, BUT_AR(engine)[i]->str_text);
        sfText_setOrigin(BUT_AR(engine)[i]->text, (sfVector2f) {
            sfText_getGlobalBounds(BUT_AR(engine)[i]->text).width / 2,
            sfText_getGlobalBounds(BUT_AR(engine)[i]->text).height / 2 +
            MARGE / 2
        });
        sfText_setPosition(BUT_AR(engine)[i]->text, (sfVector2f) {
            BUT_AR(engine)[i]->pos.x + BUT_AR(engine)[i]->rect_size.x / 2,
            BUT_AR(engine)[i]->pos.y + BUT_AR(engine)[i]->rect_size.y / 2
        });
    }
}
