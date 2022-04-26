##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## compile project with libmy
##

SRC	=	sources/main_my_world.c	\
		sources/my_world.c	\
		sources/button.c	\
		sources/menu.c	\
		sources/create_text_rect_vect.c	\
		sources/check_colli.c	\
		sources/sound_volume.c	\
		sources/shape_handler.c 				\
		sources/color_editor.c 			\
		sources/create_destroy_music.c	\
		sources/world.c                          \
		sources/str_to_int.c                        \
		sources/timer.c                             \
		sources//map.c                                       \
		sources/events.c                            \
		sources/ev_game_button_ext.c 				\
		sources/tools.c                             \
		sources/tool_event.c 						\
		sources/structs.c                           \
		sources/iso_points.c                        \
		sources/frame_rate.c	\
		sources/size_map.c	\
		sources/button_sprite.c	\
		sources/sprite.c	\
		sources/game_button.c	\
		sources/event_game_button.c	\
		sources/info_button.c	\
		sources/add_text_button_game.c	\
		sources/create_other_button.c	\
		sources/my_event.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_world

MFLAGS	= -lm

LDFLAGS =       -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C libmy
	gcc $(OBJ) -L libmy/ -o $(NAME) -lmy $(LDFLAGS) $(MFLAGS)

clean:
	$(RM) sources/*.o
	$(RM) *.o
	make clean -C libmy
	$(RM) ./a.out

fclean:	clean
	$(RM) $(NAME)
	make fclean -C libmy

re:	fclean all

tests_run:
	make
	./tests/mytest.sh

.PHONY : all clean fclean re tests_run
