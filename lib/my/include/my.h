/*
** EPITECH PROJECT, 2020
** my_lib.c
** File description:
** 06/10/2020
*/

#ifndef MY_H
#define MY_H

void my_putchar(char c);
void my_swap(int *a, int *b);
void my_put_nbr(int nb);
void my_sort_int_array(int *tab, int size);
int my_square_root(int nb, double incr_squareroot);
int my_strlen(char const *str);
int my_isneg(int n);
int my_getnbr(char const *str);
int my_getnbr_advanced(char const *str);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_str_isupper(char const *str);
int my_isnum(char const *str);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
int my_str_isnum(char const *str);
int my_show_word_array(char * const *tab);
int my_first_wordlen(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);
int size_tab_wordarray(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
char *convert_base(char const *nbr, char const *base_from, char const *base_to);
char **my_str_to_word_array(char const *str);
char *my_strndup(char const *src, int n);
void my_putstr(char const *str);
void my_array_nbr(int nb, char *array, int array_size);
unsigned int my_atoi_size(char const *str);

#endif
