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

typedef enum {
    p_angle_x,
    m_angle_x,
    p_angle_y,
    m_angle_y,
    p_position_x,
    m_position_x,
    p_position_y,
    m_position_y,
    new_map,
    new_perlin_map,
    change_mode,
    map_mode,
    palette_color,
    edit_mode,
    get_line,

    buttons
} all_button_t;

typedef struct buttons_s {
    sfRectangleShape *rectangle;
    sfVector2f rect_size;
    sfVector2f pos;
    sfText *text;
    sfColor color;
    char *str_text;
    char *help_message;
    void (*act_funct)(void);
} button_t;

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
    bool edit_mode;
    bool draw_button;
    sfTexture *selected;
    int color_id;
    sfSoundBuffer *sound;
    bool point_mode;
} settings_t;

typedef struct {
    sfText *message;
    sfFont *font;
} help_message_t;

bool if_collision(sfVector2f pos, sfVector2i mouse_pos, sfVector2f size_rect);
void click_on_button(button_t *button, sfVector2i mouse_pos, sfEvent event);
bool curser_on_button(button_t *button, sfVector2i mouse_pos,
help_message_t *message);

void draw_button(button_t *button, sfRenderWindow *window);

#endif // BUTTON_H
