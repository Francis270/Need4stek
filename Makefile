##
## Makefile for n4s in /home/francis/Documents/CPE/CPE_2016_n4s/
##
## Made by Francois Caicedo
## Login   <caiced_f@epitech.eu>
##
## Started on  Mon May  1 16:27:07 2017 Francois Caicedo
## Last update Tue May 30 11:26:53 2017 Francois Caicedo
##

NAME		= ai

SRCS		= main.c						\
		  xstrtofloat.c						\
		  go_back.c						\
		  speed.c						\
		  direction.c						\
		  lib/my_1dc_comps.c					\
		  lib/my_1dc_utils.c					\
		  lib/my_1dcn_utils.c					\
		  lib/my_2dc_utils.c					\
		  lib/my_gets.c						\
		  lib/my_lenghts.c					\
		  lib/my_puts.c						\
		  lib/my_reallocs.c					\
		  lib/my_xlib.c

OBJS		= $(addprefix src/, $(SRCS:.c=.o))

CC		= gcc -g3

RM		= rm -f

CFLAGS		= -Iinclude/			\
 		-W -Wall -Wextra		\
		-Wno-unused-parameter		\
 		-ansi -pedantic			\
		-std=gnu99			\
 		$(LIBS)

LDFLAGS		= $(LIBS)

ifeq		($(DEBUG),yes)
		CC += -g3
endif

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
