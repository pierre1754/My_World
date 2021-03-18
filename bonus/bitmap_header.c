/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include "bitmap.h"

void make_bmp_header(bmp_header_t *header, size_t size)
{
    header->magic = htobe16(0X424D);
    header->size = sizeof(bmp_header_t) + sizeof(bmp_info_header_t) +
    size * size * sizeof(uint32_t);
    header->_app1 = 0;
    header->_app2 = 0;
    header->offset = sizeof(bmp_header_t) + sizeof(bmp_info_header_t);
}

void make_bmp_info_header(bmp_info_header_t *header , size_t size)
{
    header->size = sizeof(bmp_info_header_t);
    header->width = size;
    header->height = size;
    header->planes = 1;
    header->bpp = 32;
    header->compression = 0;
    header->raw_data_size = size * size * sizeof(uint32_t);
    header->h_resolution = 0;
    header->v_resolution = 0;
    header->palette_size = 0;
    header->important_colors = 0;
}