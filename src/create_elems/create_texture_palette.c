/*
** EPITECH PROJECT, 2020
** change_size.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

void create_texture_palette(void)
{
    engine_t *engine = get_engine();
    DIR *d = opendir("asset/textures/");
    struct dirent *file_info = readdir(d);
    int i = 0;
    char *temp = NULL;

    engine->texture_palette = malloc(sizeof(sfTexture *) * tex_nbr);
    while (file_info != NULL && i < tex_nbr) {
        temp = my_strdup_plus(my_strdup("asset/textures/"),
        my_strlen("asset/textures/"), my_strlen(file_info->d_name));
        strcat(temp, file_info->d_name);
        if (my_strncmp(file_info->d_name, "..", 2)) {
            engine->texture_palette[i] = sfTexture_createFromFile(temp, NULL);
            i++;
        }
        file_info = readdir(d);
    }
}
