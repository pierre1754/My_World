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

typedef enum {
    nothing,
    texture,
    color,

    mode_nbr
} draw_mode_t;

typedef struct buttons_s {
    LIST_ENTRY(buttons_s) entries;
    sfRectangleShape *rectangle;
    sfVector2f pos;
    sfText *text;
    sfColor color;
    char *str_text;
    char *help_message;
    void (*act_funct)(void);
} buttons_t;

typedef struct {
    int zoom;
    float angle_x;
    float angle_y;
    int pos_x;
    int pos_y;
    int max_x;
    int max_y;
    bool on_button;
    bool draw_line;
    int draw_mode;
    bool is_loaded;
    int seed;
    float depth;
    float freq;
    int radius;
    sfColor color;
} settings_t;

typedef struct {
    sfText *message;
    sfFont *font;
} help_message_t;

void curser_on_button(buttons_t *button_head, sfRenderWindow *window,
settings_t *settings, help_message_t *message);
void click_on_button(buttons_t *button_head, sfRenderWindow *window,
sfEvent event);
void draw_button(buttons_t *button_head, sfRenderWindow *window);
void draw_text(buttons_t *button_head, sfRenderWindow *window);

#endif // BUTTON_H
