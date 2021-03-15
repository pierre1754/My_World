##
## EPITECH PROJECT, 2020
## Base
## File description:
## Main Makefile
##

SRC		 =	src/create_elems/create_engine.c									\
			src/create_elems/create_settings.c									\
			src/create_elems/create_buttons.c									\
			src/create_elems/create_window.c									\
			src/create_elems/create_map.c										\
			src/create_elems/create_color.c										\
			src/create_elems/create_time.c										\
			src/create_elems/create_vertex.c									\
			src/create_elems/create_help_message.c								\
			src/create_elems/create_render.c									\
			src/destroy_elems/destroy_engine.c									\
			src/destroy_elems/destroy_settings.c								\
			src/destroy_elems/destroy_buttons.c									\
			src/destroy_elems/destroy_window.c									\
			src/destroy_elems/destroy_map.c										\
			src/destroy_elems/destroy_clock.c									\
			src/destroy_elems/destroy_help_message.c							\
			src/destroy_elems/destroy_color.c									\
			src/destroy_elems/destroy_shader.c									\
			src/destroy_elems/destroy_render.c									\
			src/destroy_elems/destroy_array.c									\
			src/draw_elems/draw_elem.c											\
			src/draw_elems/draw_help.c											\
			src/draw_elems/draw_map.c											\
			src/draw_elems/draw_shader.c										\
			src/get_elems/get_event.c											\
			src/get_elems/edit_map.c											\
			src/get_elems/get_scroll.c											\
			src/get_elems/get_elem.c											\
			src/get_elems/get_color.c											\
			src/get_elems/get_on_map.c											\
			src/get_elems/get_keyboard.c										\
			src/get_elems/get_time.c											\
			src/get_elems/get_distance.c										\
			src/init_elems/init_button_head.c									\
			src/init_elems/init_buttons_text.c									\
			src/init_elems/init_one_button/init_angle/init_angle_plus_x.c		\
			src/init_elems/init_one_button/init_angle/init_angle_minus_x.c		\
			src/init_elems/init_one_button/init_angle/init_angle_plus_y.c		\
			src/init_elems/init_one_button/init_angle/init_angle_minus_y.c		\
			src/init_elems/init_one_button/init_map_modif/init_new_map.c		\
			src/init_elems/init_one_button/init_mode/init_cart_mode.c			\
			src/init_elems/init_one_button/init_mode/init_change_mode.c			\
			src/init_elems/init_one_button/init_pos/init_plus_x.c				\
			src/init_elems/init_one_button/init_pos/init_minus_x.c				\
			src/init_elems/init_one_button/init_pos/init_plus_y.c				\
			src/init_elems/init_one_button/init_pos/init_minus_y.c				\
			src/init_elems/init_one_button/init_map_modif/init_new_perlin_map.c	\
			src/init_elems/init_one_button/init_map_modif/init_color_palette.c	\
			src/init_elems/init_one_button/init_mode/init_edit_mode.c			\
			src/init_elems/init_map_elems/init_map.c							\
			src/init_elems/init_map_elems/init_color.c							\
			src/init_elems/init_map_elems/calc_map.c							\
			src/init_elems/init_elem.c											\
			src/init_elems/init_map_elems/init_map_perl.c						\
			src/set_elems/clear_map.c											\
			src/set_elems/set_elem.c											\
			src/set_elems/set_iso_point.c										\
			src/set_elems/dup_2d.c												\
			src/set_elems/dup_color.c											\
			src/set_elems/set_pos_help_message.c								\
			src/start_engine.c													\
			src/button_command/change_size.c									\
			src/button_command/change_draw_line.c								\
			src/button_command/change_draw_mode.c								\
			src/button_command/change_color.c									\
			src/button_command/change_edit_mode.c								\
			src/button_command/change_angle.c									\
			src/keyboard_command/key_zoom.c										\
			src/keyboard_command/key_move.c										\
			src/keyboard_command/key_map.c										\
			src/keyboard_command/key_save.c										\
			src/set_elems/refresh_map/refresh_vertex.c							\
			src/set_elems/refresh_map/refresh_map.c								\
			src/set_elems/refresh_map/refresh_map_line.c						\
			src/load_map/read_map.c												\
			src/load_map/str_to_line_array.c									\
			src/load_map/file_to_map.c											\
			src/perlin_noise/perlin_noise.c										\
			src/save_map/save_map.c												\
			src/ascii_map/loop_ascii.c											\
			src/ascii_map/get_ascii_event.c										\
			src/ascii_map/create_ascii_map.c									\
			src/ascii_map/draw_ascii_map.c										\

SRC_MAIN =	main.c	\

SRC_TEST =

OBJ =	$(SRC:.c=.o)

OBJ_MAIN =	$(SRC_MAIN)

OBJ_TEST =	$(SRC_TEST:.c=.o)

CFLAGS	=	-I include -I lib/button/include -I lib/my/include -L lib/my -L lib/button -lmy -lbutton -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm -Wall -Wextra -W

CFLAGS_TEST	=	--coverage -lcriterion

CFLAGS_DEBUG =	-g

NAME =	my_world

NAME_TEST =	unit_tests

$(NAME): $(OBJ) $(OBJ_MAIN)
	@make -C lib/my
	@make -C lib/button
	@(gcc $(OBJ) $(OBJ_MAIN) -o $(NAME) $(CFLAGS)) > /dev/null

all:	$(NAME)

clean:
	@make clean -C lib/my
	@(rm -f $(OBJ)) > /dev/null
	@find . -name "*.gcno" -delete
	@find . -name "*.gcda" -delete
	@find . -name "*.o" -delete

fclean:	clean
	@make fclean -C lib/my
	@make fclean -C lib/button
	@rm -f $(NAME)
	@(rm -f $(NAME) $(NAME_TEST)) > /dev/null
	@(rm -rf tests/coverage) > /dev/null
	@$(ECHO) $(CLEAR)

re:	fclean all

debug:
	@make -C lib/my
	@make -C lib/button
	gcc $(SRC) $(SRC_MAIN) -o $(NAME) $(CFLAGS) $(CFLAGS_DEBUG)

unit_tests: $(OBJ_TEST)
	@make -C lib/my
	@make -C lib/button
	@(gcc -o $(NAME_TEST) $(OBJ_TEST) $(SRC) $(CFLAGS_TEST) $(CFLAGS)) > /dev/null
	./$(NAME_TEST)

tests_run:	re unit_tests

gcovr: tests_run
	@gcovr --exclude tests
	@gcovr --exclude tests --branch

gen_html: unit_tests
	@(mkdir -p tests/coverage) > /dev/null
	@(lcov -c -d . --output-file tests/coverage/lcov) > /dev/null
	@(genhtml tests/coverage/lcov --output-directory tests/coverage) > /dev/null

html_run: gen_html
	@(firefox tests/coverage/index.html) > /dev/null
