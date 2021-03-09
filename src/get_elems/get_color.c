/*
** EPITECH PROJECT, 2020
** get_vertex.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

sfColor get_color(int hight)
{
    switch (hight) {
    case 2:
        return sfColor_fromRGB(255, 255, 255);
    case 1:
        return sfColor_fromRGB(128, 128, 128);
    case 0:
        return sfColor_fromRGB(64, 64, 64);
    default:
        return sfWhite;
    }
}

sfTexture *get_texture(int hight)
{
    switch (hight) {
    case 2:
        return sfTexture_createFromFile("asset/grass.png", NULL);
    case 1:
        return sfTexture_createFromFile("asset/dirt.png", NULL);
    case 0:
        return sfTexture_createFromFile("asset/sand.png", NULL);
    default:
        return sfTexture_createFromFile("asset/grass.png", NULL);
    }
}
