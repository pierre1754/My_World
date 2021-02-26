##
## EPITECH PROJECT, 2020
## B-CPE-100-REN-1-1-cpoolday10-pierre.hamel
## File description:
## Makefile
##

SRC =	curser_on_button.c		\
		click_on_button.c		\
		draw_button.c			\

OBJ =	$(SRC:.c=.o)

CFLAGS	=	-I include/ -g

NAME =	libbutton.a

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

all:	$(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)

re:	fclean all
