	##
## Makefile for wolf3d in /home/Rev/wolf3d
## 
## Made by Roméo Nahon
## Login	 <Rev@epitech.net>
## 
## Started on	Sat Dec	24 16:07:40 2016 Roméo Nahon
## Last update	Sat Dec	24 16:07:40 2016 Roméo Nahon
##

SRC = 	init.c 			\
		loop.c			\
		main.c			\
		minimap.c		\
		draw.c			\
		src/move_forward.c	\
		src/raycast.c		\
		src/my_put_pixel.c	\
		src/my_draw_line.c	\
		player.c			\
		raycast_next.c		\
		color.c				\
		color_next.c		\
		move.c				\
		animation.c			\
		init_object.c		\
		display.c			\
		menu.c				\
		check_key.c			\
		init_next.c

OBJ = $(SRC:.c=.o)

NAME = wolf3d

all: $(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -lcsfml-graphics -lcsfml-window -lc_graph_prog -lm -Llib/my -lmy -o $(NAME)
	rm -f $(OBJ)

val: $(SRC)
	gcc -g3 $(SRC) -lcsfml-window -lcsfml-graphics -lc_graph_prog -lm -Llib/my -lmy -o $(NAME)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *~
	rm -f *#

re: fclean all

.PHONY: $(NAME) all clean
