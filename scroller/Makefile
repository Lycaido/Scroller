CC      =       gcc

RM      =       rm -f

NAME    =       scroller

SRC     =       main.c				\
				init.c				\
				init_next.c			\
				init_next_2.c		\
				init_next_3.c		\
				init_stars.c		\
				init_comete.c		\
				init_asteroide.c	\
				loop.c				\
				draw_object.c		\
				draw_scene.c		\
				draw_scene_next.c	\
				stars.c				\
				stars_next.c		\
				tracker.c			\
				sphere.c			\
				calc_dir_vector.c	\
				light.c				\
				player.c			\
				keyboard.c			\
				collision.c			\
				init_score.c		\
				opacity.c			\

OBJ     =       $(SRC:.c=.o)

##CFLAGS  +=      -Wextra -Wunused -Werror -ansi -Wpedantic -W -Wimplicit

all:            $(NAME)

$(NAME):        $(OBJ)
		$(CC) $(OBJ) -Llib/my -lmy -lcsfml-graphics -lcsfml-window -lc_graph_prog -lm -o $(NAME)

clean:
		$(RM) $(OBJ) $(HASHTAG)
		rm -f *~
		rm -f *#

fclean:         clean
		$(RM) $(NAME)

re:             fclean all

val:            re
		$(CC) -g3 $(SRC) -Llib/my -lmy  -lcsfml-graphics -lcsfml-window -lc_graph_prog -lm -o $(NAME)

.PHONY:         all clean fclean re
