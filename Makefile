##
## Makefile for wold3d in /home/arthur/delivery/wolf3d
##
## Made by Arthur Philippe
## Login   <arthur@epitech.net>
##
## Started on  Tue Dec 20 10:21:11 2016 Arthur Philippe
## Last update Tue Dec 27 14:50:59 2016 Arthur Philippe
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
		src/wf_errors.c		\
		src/utilities_disp.c	\
		src/wf_interact.c	\
		src/wf_core.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-W -Wextra -Wall

##CFLAGS	+=	-Werror

CFLAGS	+=	-I include/

LDFLAGS	=	-lm -lc_graph_prog

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
