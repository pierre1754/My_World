/*
** EPITECH PROJECT, 2019
** PROJECT_NAME
** File description:
** DESCRIPTION
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include "drawing.h"
#include "bitmap.h"

void create_bitmap_from_buffer(size_t size,
    int * buffer, char *filepath)
{
    int fd = open (filepath, O_CREAT | O_TRUNC | O_WRONLY , 0644) ;

    write_bmp_header(fd, size);
    write_bmp_info_header(fd, size);
    write(fd, buffer, size * size * sizeof(*buffer));
    close(fd);
}

int main(int ac, char **av)
{
    char *buf = NULL;
    int *array = NULL;
    int size = 0;
    int adv = 0;

    if (ac != 3)
        return 84;
    buf = read_map(av[1]);
    size = atoi(av[2]);
    if (!buf || !size)
        return 84;
    array = malloc(sizeof(int) * size * size);
    for (; *buf; buf++, adv++) {
        array[adv] = 7 * atoi(buf);
        for (; *buf != ',' && *buf != '\n' && *buf; buf++);
    }
    create_bitmap_from_buffer(100, array, "image");
    return EXIT_SUCCESS;
}
