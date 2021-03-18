/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include <unistd.h>
#include "drawing.h"
#include "bitmap.h"

void write_bmp_header (int fd, size_t size)
{
    bmp_header_t test = {0};

    make_bmp_header(&test, size);
    write(fd, &test, sizeof(bmp_header_t));
}

void write_bmp_info_header (int fd, size_t size)
{
    bmp_info_header_t test = {0};

    make_bmp_info_header(&test, size);
    write(fd, &test, sizeof(bmp_info_header_t));
}
