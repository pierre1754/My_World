/*
** EPITECH PROJECT, 2020
** my_hunter.c
** File description:
** 17/11/2020
*/

#ifndef MY_WORLD_H
#define MY_WORLD_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <sys/queue.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "my.h"

#define nbr_int_settings 7

// MACRO FOR STRUCTURES
#define GET_WINDOW(engine) (engine->window->window)
#define GET_WINDOW_SIZE(engine) (engine->window->window_size)

typedef struct buttons_s {
    LIST_ENTRY(buttons_s) entries;
    sfRectangleShape *rectangle;
    sfText *text;
    sfVector2f pos;
} buttons_t;

typedef struct {
    int zoom;
    int angle_x;
    int angle_y;
    int pos_x;
    int pos_y;
    int max_x;
    int max_y;
} settings_t;

typedef struct {
    sfRenderWindow *window;
    sfVector2f window_size;
} window_t;

typedef struct {
    char **map_3d;
    sfVector2f **map_2d;
} map_t;

typedef struct {
    sfEvent envent;
    settings_t *settings;
    LIST_HEAD(, buttons_s) buttons;
    window_t *window;
} engine_t;

// CREATE_COMPONENT
void create_settings(void);
void create_buttons(void);
void create_window(void);
void create_map(void);
engine_t *get_engine(void);

// DESTROY_COMPONENTS
void destroy_settings(void);
void destroy_buttons(void);
void destroy_window(void);
void destroy_map(void);


#endif // MY_WORLD_H
