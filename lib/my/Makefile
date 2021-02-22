##
## EPITECH PROJECT, 2020
## B-CPE-100-REN-1-1-cpoolday10-pierre.hamel
## File description:
## Makefile
##

SRC =	./my_compute_power_rec.c		\
		./my_compute_square_root.c		\
		./my_find_prime_sup.c			\
		./my_first_wordlen.c			\
		./my_getnbr.c					\
		./my_isneg.c					\
		./my_isnum.c					\
		./my_is_prime.c					\
		./my_putchar.c					\
		./my_put_nbr.c					\
		./my_putstr.c					\
		./my_revstr.c					\
		./my_showmem.c					\
		./my_showstr.c					\
		./my_show_word_array.c			\
		./my_sort_int_array.c			\
		./my_square_root.c				\
		./my_strcapitalize.c			\
		./my_strcat.c					\
		./my_strcmp.c					\
		./my_strcpy.c					\
		./my_strdup.c					\
		./my_str_isalpha.c				\
		./my_str_islower.c				\
		./my_str_isnum.c				\
		./my_str_isprintable.c			\
		./my_str_isupper.c				\
		./my_strlen.c					\
		./my_strlowcase.c 				\
		./my_strncat.c					\
		./my_strncmp.c					\
		./my_strncpy.c					\
		./my_strstr.c					\
		./my_str_to_word_array.c		\
		./my_strupcase.c				\
		./my_swap.c						\
		./size_tab_wordarray.c			\
		./my_array_nbr.c				\
		./convert_base.c				\
		./my_showstr.c					\
		./my_strndup.c					\
		./my_atoi_size.c				\

OBJ =	$(SRC:.c=.o)

CFLAGS	=	-I include/ -g

NAME =	libmy.a

$(NAME): $(OBJ)
	cp include/my.h ../../include
	@ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

all:	$(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)

re:	fclean all
