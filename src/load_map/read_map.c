/*
** EPITECH PROJECT, 2020
** my_skoban
** File description:
** read_arg
*/

#include "my_world.h"

static int check_commas(char *file)
{
    int len = 0;
    int len_next = 0;
    int j = 0;

    for (int i = 0; file[i]; i++) {
        for (j = i + 1; file[j] && file[j] != '\n'; j++) {
            if (file[j] == ',') {
                len_next++;
            }
        }
        if (len != 0 && len_next != len)
            return 1;
        len = len_next;
        len_next = 0;
        i += j - i;
    }
    return 0;
}

char *verif_map(char *file)
{
    if (check_commas(file))
        return NULL;
    for (int i = 0; file[i]; i++) {
        if ((file[i] < '0' || file[i] > '9') &&
        file[i] != ',' && file[i] != '\n' && file[i] != ';')
            return NULL;
    }
    return file;
}

char *my_strdup_plus(char *str, int basic, int plus)
{
    char *result = malloc(sizeof(char) * (basic + plus + 1));

    memset(result, '\0', basic + plus + 1);
    if (str)
        my_strcpy(result, str);
    free(str);
    return result;
}

char *loop_read(int fd, char *temp, char *buffer)
{
    int ret = 1;
    int iter = 0;
    int len = LEN;

    do {
        iter++;
        len = (iter * LEN);
        memset(temp, '\0', LEN + 1);
        ret = read(fd, temp, LEN);
        buffer = my_strcat(my_strdup_plus(buffer, len, ret), temp);
        if (ret == LEN && !temp[ret - 1])
            break;
    } while (ret == LEN);
    return buffer;
}

char *read_map(char *path)
{
    char *temp = malloc(sizeof(char) * (LEN + 1));
    char *buffer = malloc(sizeof(char) * (LEN + 1));
    int fd = open(path, O_RDONLY);

    if (fd == -1)
        return NULL;
    memset(buffer, '\0', LEN + 1);
    buffer = loop_read(fd, temp, buffer);
    free(temp);
    close(fd);
    return verif_map(buffer);
}
