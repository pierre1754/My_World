/*
** EPITECH PROJECT, 2020
** get_on_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

float get_distance(sfVector2f point_1, sfVector2f point_2)
{
    return sqrt(pow(point_2.x - point_1.x, 2) + pow(point_2.y - point_1.y, 2));
}
