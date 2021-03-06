##
## Makefile for wold3d in /home/arthur/delivery/wolf3d
##
## Made by Arthur Philippe
## Login   <arthur@epitech.net>
##
## Started on  Tue Dec 20 10:21:11 2016 Arthur Philippe
## Last update Sun Jan 15 22:25:10 2017 Arthur Philippe
##

CC	=	gcc

RM	=	rm -f

NAME	=	wolf3d

SRCS	=	src/my_put_pixel.c	\
		src/my_draw_line.c	\
		src/move_forward.c	\
		src/raycast.c		\
		src/main.c		\
		src/open_window.c	\
		src/wf_openfile.c	\
		src/wf_openfile_b.c	\
		src/wf_errors.c		\
		src/utilities_disp.c	\
		src/utilities_nbr.c	\
		src/wf_interact.c	\
		src/wf_game_parser.c	\
		src/wf_nuke.c		\
		src/wf_core.c		\
		src/wf_darkness.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror

##CFLAGS	+=	-Werror

CFLAGS	+=	-I include/

LDFLAGS	=	-lm -lcsfml-window -lcsfml-system -lcsfml-graphics

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
