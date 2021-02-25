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

#ifndef LIST_FOREACH_SAFE
#define LIST_FOREACH_SAFE(var, head, field, tvar)          \
        for ((var) = LIST_FIRST((head));                   \
            (var) && ((tvar) = LIST_NEXT((var), field), 1);\
            (var) = (tvar))
#endif

// MACRO FOR STRUCTURES
#define GET_SET_Z(engine) (engine->settings->zoom)
#define GET_SET_AX(engine) ( engine->settings->angle_x)
#define GET_SET_AY(engine) ( engine->settings->angle_y)
#define GET_SET_PX(engine) ( engine->settings->pos_x)
#define GET_SET_PY(engine) ( engine->settings->pos_y)
#define GET_SET_MX(engine) ( engine->settings->max_x)
#define GET_SET_MY(engine) ( engine->settings->max_y)

#define GET_LISTHEAD(engine) (&engine->buttons)

#define GET_WINDOW(engine) (engine->window->window)
#define GET_WINDOW_SIZE(engine) (engine->window->window_size)

#define GET_MAP_2D(engine) (engine->map->map_2d)
#define GET_MAP_3D(engine) (engine->map->map_3d)
#define GET_MAP_VER(engine) (engine->map->map_ver)

// MACRO FOR CALC
#define ANGLE_X_RAD(engine) GET_SET_AX(engine) * 3.14 / 180
#define ANGLE_Y_RAD(engine) GET_SET_AY(engine) * 3.14 / 180

typedef struct buttons_s {
    LIST_ENTRY(buttons_s) entries;
    sfRectangleShape *rectangle;
    sfVector2f pos;
    sfText *text;
    sfFont *font;
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
    int **map_3d;
    sfVector2f **map_2d;
    sfVertexArray ***map_ver;
} map_t;

typedef struct {
    sfEvent event;
    settings_t *settings;
    LIST_HEAD(, buttons_s) buttons;
    window_t *window;
    map_t *map;
} engine_t;

typedef struct {
    sfVector2f point1;
    sfVector2f point2;
    sfVector2f point3;
    sfVector2f point4;
} square_t;

// CREATE_COMPONENT
void create_settings(void);
void create_buttons(void);
buttons_t *get_new_button(void);
void create_window(void);
void create_map(void);
void create_map_3d(void);
void create_map_2d(void);
void create_map_ver(void);
engine_t *get_engine(void);
void create_engine(void);

// DESTROY_COMPONENTS
void destroy_settings(void);
void destroy_buttons(void);
void destroy_one_button(buttons_t *button);
void destroy_window(void);
void destroy_map(void);
void destroy_map_3d(void);
void destroy_map_2d(void);
void destroy_map_ver(void);
void destroy_engine(void);

// INIT_COMPONENTS
void init_map_3d(void);
void init_map_2d(void);
void init_map_ver(void);
void init_elem(void);

// GET_ELEM
sfVector2f get_iso_point(int x, int y, int z);
square_t *create_quad(sfVector2f point1, sfVector2f point2, sfVector2f point3,
sfVector2f point4);
sfVertexArray *create_vertex_quad(square_t *quad, sfVertexArray *array);
void get_event(void);
void get_elem(void);

// SET_ELEM
void set_elem(void);

// DRAW_ELEM
void draw_elem(void);
void draw_2d_map(void);

void start_engine(void);

#endif // MY_WORLD_H
