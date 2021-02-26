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

typedef struct buttons_s {
    LIST_ENTRY(buttons_s) entries;
    sfRectangleShape *rectangle;
    sfVector2f pos;
    sfText *text;
    sfFont *font;
} buttons_t;

void get_pos_button(buttons_t *button_head);
void curser_on_button(buttons_t *button_head, sfRenderWindow *window);
void click_on_button(buttons_t *button_head, sfRenderWindow *window);
void draw_button(buttons_t *button_head, sfRenderWindow *window);

#endif // BUTTON_H
