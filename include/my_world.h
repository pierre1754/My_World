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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
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

#define nbr_int_settings 13
#define MARGE 10
#define LEN 8

#define MARGE_MAP 1

#define TABLE_SIZE 256

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
#define GET_SET_LINE(engine) (engine->settings->draw_line)
#define GET_SET_MODE(engine) (engine->settings->draw_mode)
#define GET_SET_LOD(engine) (engine->settings->is_loaded)
#define GET_SEED(engine) (engine->settings->seed)
#define GET_DEPTH(engine) (engine->settings->depth)
#define GET_FREQ(engine) (engine->settings->freq)
#define GET_SET_RAD(engine) (engine->settings->radius)
#define GET_COLOR(engine) (engine->settings->color)
#define GET_EDIT_MODE(engine) (engine->settings->edit_mode)
#define GET_DRAW_BUTTON(engine) (engine->settings->draw_button)

#define GET_LISTHEAD(engine) (&engine->buttons)

#define SHADER_NAME "asset/water_shader.frag"

#define GET_WINDOW(engine) (engine->window->window)
#define GET_WINDOW_SIZE(engine) (engine->window->window_size)

#define GET_MAP_2D(engine) (engine->map->map_2d)
#define GET_MAP_2D_BASE(engine) (engine->map->map_2d_base)
#define GET_MAP_3D(engine) (engine->map->map_3d)
#define GET_MAP_3D_BASE(engine) (engine->map->map_3d_base)
#define GET_MAP_COLOR(engine) (engine->map->map_color)
#define GET_MAP_TEX(engine) (engine->map->map_tex)
#define GET_MAP_LINES(engine) (engine->map->map_lines)
#define GET_MAP_ORIGIN(engine) (engine->map->map_origin)
#define GET_COLOR_2D(engine) (engine->map->color_2d)
#define GET_TEX_2D(engine) (engine->map->texture_2d)

#define GET_CLOCK(engine) (engine->time->clock)
#define GET_ELAPSED(engine) (engine->time->time_elapsed)

// MACRO FOR CALC
#define ANGLE_X_RAD(engine) (GET_SET_AX(engine) * 3.14 / 180)
#define ANGLE_Y_RAD(engine) (GET_SET_AY(engine) * 3.14 / 180)

typedef enum {
    plus_x,
    minus_x,
    plus_y,
    minus_y,
    cart_mode,
    change_mode,
    new_map,
    plus_angle_x,
    minus_angle_x,
    plus_angle_y,
    minus_angle_y,
    new_perlin_map,
    color_palette,
    edit_mode,

    but_nbr
} all_buttons_t;

typedef struct {
    sfRenderWindow *window;
    sfVector2f window_size;
} window_t;

typedef struct {
    sfClock *clock;
    float time_elapsed;
} time_elapsed_t;

typedef struct {
    int **map_3d;
    int **map_3d_base;
    sfVector2f **map_2d;
    sfVector2f **map_2d_base;
    sfVertexArray ***map_color;
    sfVertexArray ***map_tex;
    sfVertexArray ***map_lines;
    sfVertexArray ***map_origin;
    sfColor **color_2d;
    sfTexture ***texture_2d;
} map_t;

typedef struct {
    sfTexture *dirt;
    sfTexture *grass;
    sfTexture *sand;
    sfRenderStates states;
} render_states_t;

typedef struct {
    sfTexture *water;
    sfShader *shader;
    sfFloatRect shader_rect;
    sfRenderStates states;
} render_shader_t;

typedef struct {
    sfEvent event;
    settings_t *settings;
    LIST_HEAD(, buttons_s) buttons;
    window_t *window;
    map_t *map;
    time_elapsed_t *time;
    help_message_t *message;
    render_states_t *render;
    render_shader_t *shade;
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
void create_map(char *file);
int **create_map_3d(void);
sfVector2f **create_map_2d(void);
sfVertexArray ***create_map_ver(void);
sfColor **create_color_2d(void);
sfTexture ***create_texture_2d(void);
engine_t *get_engine(void);
void create_time(void);
sfVertexArray *create_vertex_color(square_t quad, sfVertexArray *array, int i,
int j);
sfVertexArray *create_vertex_tex(square_t quad, sfVertexArray *array);
sfVertexArray *create_vertex_line(line_t line, sfVertexArray *array);
void create_help_message(void);
void create_engine(char *file);
void create_render(void);
void create_shader(void);

// DESTROY_COMPONENTS
void destroy_settings(void);
void destroy_buttons(void);
void destroy_one_button(buttons_t *button);
void destroy_window(void);
void destroy_map(void);
void destroy_help_message(void);
void destroy_clock(void);
void destroy_map_3d(int **map);
void destroy_map_2d(sfVector2f **map);
void destroy_map_ver(sfVertexArray ***map);
void destroy_color_2d(void);
void destroy_texture_2d(void);
void destroy_shader(void);
void destroy_render(void);
void destroy_array(void);
void destroy_engine(void);

// INIT_COMPONENTS
void init_map_int(int **map);
void init_perlin_map(int **map);
void calc_map_vec(sfVector2f **map, int **map_int);
void init_map_color(sfVertexArray ***map, sfVector2f **map_vec);
void init_map_tex(sfVertexArray ***map, sfVector2f **map_vec);
void init_map_line(void);
void init_color_2d(void);
void init_texture_2d(void);
void clear_map_ver(sfVertexArray ***map);
void clear_map_lines(sfVertexArray ***map);
void init_perlin(void);
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
// CART MODE
void init_cart_mode_rect(engine_t *engine, buttons_t *button,
sfVector2f rect_size);
void init_cart_mode_text(buttons_t *button,
sfVector2f rect_size);
void init_cart_mode(buttons_t *button);
// CHANGE MODE
void init_change_mode_rect(engine_t *engine, buttons_t *button,
sfVector2f rect_size);
void init_change_mode_text(buttons_t *button,
sfVector2f rect_size);
void init_change_mode(buttons_t *button);
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
// NEW_PERLIN_MAP
void init_new_perlin_map_rect(buttons_t *button, sfVector2f rect_size);
void init_new_perlin_map_text(buttons_t *button, sfVector2f rect_size);
void init_new_perlin_map(buttons_t *button);
// COLOR_PALETTE
void init_color_palette_rect(engine_t *engine, buttons_t *button,
sfVector2f rect_size);
void init_color_palette_text(buttons_t *button, sfVector2f rect_size);
void init_color_palette(buttons_t *button);
// EDIT_MODE
void init_edit_mode_rect(engine_t *engine, buttons_t *button,
sfVector2f rect_size);
void init_edit_mode_text(buttons_t *button,
sfVector2f rect_size);
void init_edit_mode(buttons_t *button);

void init_text_obj(void);
void init_buttons_text(void);
void init_elem(void);

// GET_ELEM
sfColor get_color(int hight);
sfTexture *get_texture(int hight);
void get_elem(void);
void shortcut(void);
void get_keyboard(void);
void get_scroll(void);
void get_event(void);
void get_on_map(void);
void get_on_map_minus(void);
void edit_map(void);
void edit_color_map(void);
void edit_texture_map(void);
void get_mouse_input(void);
void get_selection(void);
void get_time(void);
float get_distance(sfVector2f point_1, sfVector2f point_2);

// SET_ELEM
int *intdup(int *cp_src, int *src);
int **intdup_2d(int **src);
sfVector2f **vectordup_2d(sfVector2f **src);
sfVertexArray ***vertexdup_2d(void);
sfVertexArray ***linedup_2d(void);
sfColor **color_dup_2d(sfColor **src);
sfTexture ***texture_dup_2d(sfTexture ***src);
void set_pos_help_message(void);
void set_elem(void);

// DRAW_ELEM
sfVector2f set_iso_point(int x, int y, int z);
void draw_each_map(int i, int j);
void draw_map(void);
void draw_help(void);
void draw_elem(void);
void draw_shader(void);

// BUTTON_COMMAND
void resize_map(void);
void recalc_map(void);
void increase_map_x(void);
void decrease_map_x(void);
void increase_map_y(void);
void decrease_map_y(void);
void increase_zoom(void);
void decrease_zoom(void);
void change_draw_line(void);
void change_draw_mode(void);
void increase_angle_x(void);
void decrease_angle_x(void);
void increase_angle_y(void);
void decrease_angle_y(void);
void change_color_map(void);
void change_edit_mode(void);

// KEY_COMMAND
void key_map(void);
void key_move(void);
void key_zoom(void);

// REFRESH_MAP
sfVertexArray *refresh_vertex_quad(square_t quad, sfVertexArray *array);
void refresh_map_ver(sfVertexArray ***map, sfVector2f **map_vec);
sfVertexArray *refresh_vertex_line(line_t line, sfVertexArray *array);
void refresh_map_line(void);

// READ_MAP
char *read_map(char *path);
char *verif_map(char *file);
char **init_array(int y);
char **my_str_to_line_array(char const *file);
int x_size(char *file);
int y_size(char *file);
void get_size_map(char *file);
void file_to_map(char **file);

// PERLIN_NOISE
int get_noise(int x, int y, int seed);
float lin_inter(float x, float y, float s);
float smooth_inter(float x, float y, float s);
float perlin_noise_2d(float x, float y, int seed);
float perlin_noise(float x_freq, float y_freq, int depth, int seed);

void start_engine(void);

#endif // MY_WORLD_H
