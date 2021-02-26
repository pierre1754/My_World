/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void redirect_button(int id_but, buttons_t *button)
{
    switch (id_but) {
    case plus_x:
        /* code */
        break;
    case minus_x:
        /* code */
        break;
    case plus_y:
        /* code */
        break;
    case minus_y:
        /* code */
        break;
    case plus_zoom:
        /* code */
        break;
    case minus_zoom:
        /* code */
        break;
    case cart_mode:
        /* code */
        break;
    case color_mode:
        /* code */
        break;
    }
}

void init_text_obj(void)
{
    engine_t *engine = get_engine();
    buttons_t *temp = NULL;
    int id_but = 0;

    LIST_FOREACH(temp, GET_LISTHEAD(engine), entries) {
        sfText_setFont(temp->text, temp->font);
        sfText_setColor(temp->text, sfWhite);
        sfText_setCharacterSize(temp->text, 15);
        redirect_button(id_but, temp);
        id_but++;
    }
}

void init_buttons_text(void)
{

}
