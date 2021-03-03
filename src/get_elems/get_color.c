/*
** EPITECH PROJECT, 2020
** get_vertex.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

sfColor get_color(int **map, int i, int j)
{
    int hight = map[i][j];

    switch (hight) {
    case 1:
        return sfColor_fromRGB(255, 255, 255);
    case 0:
        return sfColor_fromRGB(128, 128, 128);
    case -1:
        return sfColor_fromRGB(64, 64, 64);
    default:
        return sfWhite;
    }
}
