/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

sfVector2f get_iso_point(int x, int y, int z)
{
    engine_t *engine = get_engine();
    sfVector2f point_2d = {0, 0};

    point_2d.x = (cos(ANGLE_X_RAD(engine)) * x - cos(ANGLE_X_RAD(engine)) * y)
    * GET_SET_Z(engine) + GET_SET_PX(engine);
    point_2d.y = (sin(ANGLE_Y_RAD(engine)) * y + sin(ANGLE_Y_RAD(engine)) * x -
    z) * GET_SET_Z(engine) + GET_SET_PY(engine);
    return point_2d;
}
