/*
** EPITECH PROJECT, 2020
** my_skoban
** File description:
** read_arg
*/

#include "my_world.h"

char *verif_map(char *file)
{
    for (int i = 0; file[i]; i++) {
        if ((file[i] < '0' || file[i] > '9') &&
        file[i] != ',' && file[i] != '\n' && file[i] != ';')
            return NULL;
    }
    return file;
}

static char *my_strdup_plus(char *str, int basic, int plus)
{
    char *result = malloc(sizeof(char) * (basic + plus + 1));

    memset(result, '\0', basic + plus);
    if (str)
        my_strcpy(result, str);
    return result;
}

char *read_map(char *path)
{
    int ret = 1;
    int iter = 0;
    int len = LEN;
    char *temp = malloc(sizeof(char) * (LEN + 1));
    char *buffer = malloc(sizeof(char) * (LEN + 1));
    int fd = open(path, O_RDONLY);

    if (fd == -1)
        return NULL;
    memset(buffer, '\0', LEN + 1);
    do {
        iter++;
        len = (iter * LEN);
        memset(temp, '\0', LEN + 1);
        ret = read(fd, temp, LEN);
        buffer = my_strcat(my_strdup_plus(buffer, len, ret), temp);
        if (ret == LEN && !temp[ret - 1])
            break;
    } while (ret == LEN);
    return verif_map(buffer);
}
