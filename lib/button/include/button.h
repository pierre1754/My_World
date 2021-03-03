/*
** EPITECH PROJECT, 2020
** libbutton.c
** File description:
** 25/02/2021
*/

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <sys/queue.h>
#include <stdbool.h>
#include <stdio.h>

// typedef enum {
//     plus_x,
//     minus_x,
//     plus_y,
//     minus_y,
//     plus_zoom,
//     minus_zoom,
//     cart_mode,
//     color_mode,
//     new_map,
//     plus_angle_x,
//     minus_angle_x,
//     plus_angle_y,
//     minus_angle_y,

//     but_nbr
// } all_buttons_t;

typedef struct buttons_s {
    LIST_ENTRY(buttons_s) entries;
    sfRectangleShape *rectangle;
    sfVector2f pos;
    sfText *text;
    sfFont *font;
    char *str_text;
    void (*act_funct)(void);
} buttons_t;

typedef struct {
    int zoom;
    int angle_x;
    int angle_y;
    int pos_x;
    int pos_y;
    int max_x;
    int max_y;
    bool on_button;
    bool draw_line;
    int draw_mode;
} settings_t;

void curser_on_button(
    buttons_t *button_head,
    sfRenderWindow *window,
    settings_t *settings
);
void click_on_button(buttons_t *button_head, sfRenderWindow *window,
sfEvent event);
void draw_button(buttons_t *button_head, sfRenderWindow *window);
void draw_text(buttons_t *button_head, sfRenderWindow *window);

#endif // BUTTON_H
