/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** task02
*/

#ifndef DRAWING_H
#define DRAWING_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct point_s
{
    unsigned int x;
    unsigned int y;
} point_t;

void write_bmp_header (int fd, size_t size);
void write_bmp_info_header (int fd, size_t size);

#endif
