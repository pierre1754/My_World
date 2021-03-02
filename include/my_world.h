/*
** EPITECH PROJECT, 2020
** my_world.c
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
#include <time.h>

#include "my.h"
#include "button.h"

#define nbr_int_settings 7
#define MARGE 10

#ifndef LIST_FOREACH_SAFE
#define LIST_FOREACH_SAFE(var, head, field, tvar)          \
        for ((var) = LIST_FIRST((head));                   \
            (var) && ((tvar) = LIST_NEXT((var), field), 1);\
            (var) = (tvar))
#endif

// MACRO FOR STRUCTURES
#define GET_SETTINGS(engine) (engine->settings)
#define GET_SET_Z(engine) (engine->settings->zoom)
#define GET_SET_AX(engine) (engine->settings->angle_x)
#define GET_SET_AY(engine) (engine->settings->angle_y)
#define GET_SET_PX(engine) (engine->settings->pos_x)
#define GET_SET_PY(engine) (engine->settings->pos_y)
#define GET_SET_MX(engine) (engine->settings->max_x)
#define GET_SET_MY(engine) (engine->settings->max_y)
#define GET_SET_STATUS(engine) (engine->settings->on_button)

#define GET_LISTHEAD(engine) (&engine->buttons)

#define GET_WINDOW(engine) (engine->window->window)
#define GET_WINDOW_SIZE(engine) (engine->window->window_size)

#define GET_MAP_2D(engine) (engine->map->map_2d)
#define GET_MAP_3D(engine) (engine->map->map_3d)
#define GET_MAP_VER(engine) (engine->map->map_ver)
#define GET_MAP_LINES(engine) (engine->map->map_lines)

// MACRO FOR CALC
#define ANGLE_X_RAD(engine) (GET_SET_AX(engine) * 3.14 / 180)
#define ANGLE_Y_RAD(engine) (GET_SET_AY(engine) * 3.14 / 180)

typedef enum {
    plus_x,
    minus_x,
    plus_y,
    minus_y,
    plus_zoom,
    minus_zoom,
    cart_mode,
    color_mode,
    new_map,
    plus_angle_x,
    minus_angle_x,
    plus_angle_y,
    minus_angle_y,

    but_nbr
} all_buttons_t;

typedef struct {
    sfRenderWindow *window;
    sfVector2f window_size;
} window_t;

typedef struct {
    int **map_3d;
    sfVector2f **map_2d;
    sfVertexArray ***map_ver;
    sfVertexArray ***map_lines;
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

typedef struct {
    sfVector2f point1;
    sfVector2f point2;
} line_t;

// CREATE_COMPONENT
void create_settings(void);
void create_buttons(void);
buttons_t *get_new_button(void);
void create_window(void);
void create_map(void);
void create_map_3d(void);
void create_map_2d(void);
sfVertexArray ***create_map_ver(sfVertexArray ***map);
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
void init_map_line(void);
sfVertexArray ***clear_map_ver(sfVertexArray ***map);
void init_map(void);
void init_button_head(void);

// PLUS X
void init_plus_x_rect(engine_t *engine, buttons_t *button,
sfVector2f rect_size);
void init_plus_x_text(buttons_t *button,
sfVector2f rect_size);
void init_plus_x(buttons_t *button);

// MINUS X
void init_minus_x_rect(engine_t *engine, buttons_t *button,
sfVector2f rect_size);
void init_minus_x_text(buttons_t *button,
sfVector2f rect_size);
void init_minus_x(buttons_t *button);

// PLUS Y
void init_plus_y_rect(engine_t *engine, buttons_t *button,
sfVector2f rect_size);
void init_plus_y_text(buttons_t *button,
sfVector2f rect_size);
void init_plus_y(buttons_t *button);

// MINUS Y
void init_minus_y_rect(engine_t *engine, buttons_t *button,
sfVector2f rect_size);
void init_angle_minus_y_text(buttons_t *button,
sfVector2f rect_size);
void init_minus_y(buttons_t *button);

// PLUS ZOOM
void init_plus_zoom_rect(engine_t *engine, buttons_t *button,
sfVector2f rect_size);
void init_plus_zoom_text(buttons_t *button,
sfVector2f rect_size);
void init_plus_zoom(buttons_t *button);

// MINUS ZOOM
void init_minus_zoom_rect(engine_t *engine, buttons_t *button,
sfVector2f rect_size);
void init_minus_zoom_text(buttons_t *button,
sfVector2f rect_size);
void init_minus_zoom(buttons_t *button);

// CART MODE
void init_cart_mode_rect(engine_t *engine, buttons_t *button,
sfVector2f rect_size);
void init_cart_mode_text(buttons_t *button,
sfVector2f rect_size);
void init_cart_mode(buttons_t *button);

// COLOR MODE
void init_color_mode_rect(engine_t *engine, buttons_t *button,
sfVector2f rect_size);
void init_color_mode_text(buttons_t *button,
sfVector2f rect_size);
void init_color_mode(buttons_t *button);

// NEW MAP
void init_new_map_rect(buttons_t *button);
void init_new_map_text(buttons_t *button, sfVector2f rect_size);
void init_new_map(buttons_t *button);

// ANGLE X PLUS
void init_angle_plus_x_rect(engine_t *engine, buttons_t *button,
sfVector2f rect_size);
void init_angle_plus_x_text(buttons_t *button,
sfVector2f rect_size);
void init_angle_plus_x(buttons_t *button);

// ANGLE X MINUS
void init_angle_minus_x_rect(engine_t *engine, buttons_t *button,
sfVector2f rect_size);
void init_angle_minus_x_text(buttons_t *button,
sfVector2f rect_size);
void init_angle_minus_x(buttons_t *button);

// ANGLE Y PLUS
void init_angle_plus_y_rect(engine_t *engine, buttons_t *button,
sfVector2f rect_size);
void init_angle_plus_y_text(buttons_t *button,
sfVector2f rect_size);
void init_angle_plus_y(buttons_t *button);

// ANGLE Y MINUS
void init_angle_minus_y_rect(engine_t *engine, buttons_t *button,
sfVector2f rect_size);
void init_angle_minus_y_text(buttons_t *button,
sfVector2f rect_size);
void init_angle_minus_y(buttons_t *button);
void init_text_obj(void);
void init_buttons_text(void);
void init_elem(void);

// GET_ELEM
sfVector2f get_iso_point(int x, int y, int z);
square_t *create_quad(sfVector2f point1, sfVector2f point2, sfVector2f point3,
sfVector2f point4);
line_t *create_line(sfVector2f point1, sfVector2f point2);
sfVertexArray *create_vertex_quad(square_t *quad, sfVertexArray *array, int i,
int j);
sfVertexArray *create_vertex_line(line_t *line, sfVertexArray *array, int i,
int j);
void get_event(void);
void get_elem(void);
void print_map_pos(void);
void get_mouse_input(void);
void get_selection(void);

// SET_ELEM
void set_elem(void);

// DRAW_ELEM
void draw_elem(void);
void draw_2d_map(void);

// BUTTON_COMMAND
void resize_map(void);
void increase_map_x(void);
void decrease_map_x(void);
void increase_map_y(void);
void decrease_map_y(void);
void increase_zoom(void);
void decrease_zoom(void);
void refresh_map(void);

void start_engine(void);
int *intdup(int *cp_src, int *src);
int **intdup_2d(int **src);
sfVector2f **vectordup_2d(sfVector2f **src);
sfVertexArray ***vertexdup_2d(void);

#endif // MY_WORLD_H
