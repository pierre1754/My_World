/*
** EPITECH PROJECT, 2020
** my_world.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

static int parcing(int argc, char **argv, char **file)
{
    int temp_one = 0;
    int temp_two = 0;

    if (argc == 5 && !my_strcmp(argv[2], "--image")) {
        temp_one = my_getnbr(argv[3]);
        temp_two = my_getnbr(argv[4]);
        if (!temp_one || !temp_two || loop_ascii(argv[1], temp_one, temp_two))
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
