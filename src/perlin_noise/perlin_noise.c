/*
** EPITECH PROJECT, 2020
** set_map.c
** File description:
** 17/11/2020
*/

#include "my_world.h"

static const int table[] = {
    139, 239, 189, 109, 110, 122, 22, 129, 144, 142, 210, 242, 115, 256, 218,
    72, 24, 77, 146, 234, 237, 173, 73, 87, 140, 13, 42, 179, 185, 138, 223,
    196, 149, 51, 83, 184, 211, 143, 20, 103, 130, 141, 97, 76, 26, 225, 254,
    206, 67, 10, 48, 108, 238, 228, 8, 125, 209, 55, 221, 200, 14, 158, 78,
    155, 43, 25, 170, 114, 12, 31, 182, 236, 111, 54, 215, 191, 136, 161, 208,
    202, 44, 70, 187, 222, 181, 11, 134, 253, 192, 245, 6, 1, 95, 123, 128,
    160, 53, 86, 231, 23, 247, 212, 131, 18, 124, 199, 162, 29, 255, 107, 50,
    147, 152, 250, 197, 30, 220, 171, 251, 190, 148, 135, 120, 90, 99, 7, 46,
    159, 88, 203, 233, 164, 2, 69, 5, 252, 57, 150, 145, 59, 137, 94, 205, 102,
    226, 38, 156, 121, 16, 3, 235, 163, 118, 224, 180, 66, 64, 79, 4, 213, 63,
    207, 65, 230, 15, 27, 154, 49, 165, 93, 80, 34, 117, 186, 74, 153, 227, 84,
    249, 52, 104, 91, 68, 151, 71, 132, 177, 39, 33, 133, 45, 167, 172, 157,
    35, 193, 241, 168, 219, 58, 40, 178, 119, 28, 176, 9, 188, 106, 41, 229,
    75, 246, 198, 21, 105, 56, 100, 183, 232, 101, 19, 17, 204, 89, 98, 244,
    112, 60, 61, 36, 81, 166, 216, 194, 85, 92, 175, 174, 248, 214, 240, 47,
    169, 195, 113, 217, 126, 62, 32, 37, 82, 201, 127, 116, 96, 78
};

int get_noise(int x, int y, int seed)
{
    int temp = table[(y + seed) % TABLE_SIZE];

    return table[(temp + x) % TABLE_SIZE];
}

float lin_inter(float x, float y, float s)
{
    return x + s * (y - x);
}

float smooth_inter(float x, float y, float s)
{
    return lin_inter(x, y, s * s * (3 - 2 * s));
}

float perlin_noise_2d(float x, float y, int seed)
{
    int x_int = x;
    int y_int = y;
    float x_rest = x - x_int;
    float y_rest = y - y_int;
    int case_1 = get_noise(x_int, y_int, seed);
    int case_2 = get_noise(x_int + 1, y_int, seed);
    int case_3 = get_noise(x_int, y_int + 1, seed);
    int case_4 = get_noise(x_int + 1, y_int + 1, seed);
    float low = smooth_inter(case_1, case_2, x_rest);
    float high = smooth_inter(case_3, case_4, x_rest);

    return smooth_inter(low, high, y_rest);
}

float perlin_noise(float x_freq, float y_freq, int depth, int seed)
{
    float amp = 1.f;
    float fin = 0;
    float div = 0.1f;

    for (int i = 0; i < depth; i++) {
        div += TABLE_SIZE * amp;
        fin += perlin_noise_2d(x_freq, y_freq, seed) * amp;
        amp /= 2;
        x_freq *= 2;
        y_freq *= 2;
    }
    return fin / div;
}
