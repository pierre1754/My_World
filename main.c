/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

static int parcing(int argc, char **argv, char **file)
{
    if (argc == 3 && !my_strcmp(argv[2], "--image")) {
        if (loop_image(argv[1]))
            return 84;
        return 0;
    }
    if (argc > 2)
        return 84;
    else if (argc == 2) {
        *file = read_map(argv[1]);
        if (!*file)
            return 84;
    }
    if (!sfShader_isAvailable())
        return 84;
    return -1;
}

int main(int argc, char **argv)
{
    char *file = NULL;
    int temp = parcing(argc, argv, &file);

    if (temp != -1)
        return temp;
    create_engine(file);
    init_elem();
    start_engine();
    save_map();
    destroy_engine();
    return 0;
}
