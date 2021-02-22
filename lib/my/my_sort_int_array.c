/*
** EPITECH PROJECT, 2020
** my_sort_int_array.c
** File description:
** 02/10/2020
*/

void my_sort_int_array(int *array, int size)
{
    int last_put = 0;

    for (int adv = 0; adv < size; adv++) {
        for (int loop_adv = adv; loop_adv < size; loop_adv++) {
            if (array[adv] > array[loop_adv]) {
                last_put = array[adv];
                array[adv] = array[loop_adv];
                array[loop_adv] = last_put;
            }
        }
    }
}
