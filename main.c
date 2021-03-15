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

    if (argc > 3)
        return 84;
    if (argc == 3 && !my_strcmp(argv[2], "--ascii")) {
        if (loop_ascii(argv[1]))
            return 84;
        return 0;
    }
    else if (argc == 2 && my_getnbr(argv[1]) == 0) {
        file = read_map(argv[1]);
        if (!file)
            return 84;
    }
    create_engine(file);
    init_elem();
    start_engine();
    destroy_engine();
    return 0;
}
