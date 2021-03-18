##
## EPITECH PROJECT, 2019
## Makefile doop
## File description:
## task02
##

SRC	=	main.c						\
		drawing.c					\
		bitmap_header.c				\
		read_map.c					\

OBJ	=	$(SRC:.c=.o)

NAME	=	file_map

CFLAGS	+=	-std=gnu11	-Wall	-Wextra	-I ./include

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o	$(NAME)	$(OBJ) -lm -I ./include

clean:
	rm	-f 	$(OBJ)

fclean: clean
	rm	-f	$(NAME)
	rm -f image

re:	fclean	all
