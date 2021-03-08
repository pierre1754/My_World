/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

int main(int argc, char **argv)
{
    char *file = NULL;

    if (argc > 2)
        return 84;
    create_engine();
    if (argc == 2 && my_getnbr(argv[1]) == 0) {
        file = read_map(argv[1]);
    }
    // init_elem();
    // start_engine();
    destroy_engine();
    return 0;
}
