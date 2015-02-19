# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amulin <amulin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/17 11:06:17 by amulin            #+#    #+#              #
#    Updated: 2015/02/17 15:15:12 by amulin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Werror -Wextra

SRCS = main.c

SRCDIR = sources/

SOURCES = $(addprefix $(SRCDIR), $(SRCS))

HEADERS = includes/fdf.h

OBJECTS = $(subst .c,.o,$(SRCS))

LIB = libft/libft.a

.PHONY: all, clean, fclean, re

all: $(NAME)
	
$(NAME): $(OBJECTS)
	gcc $(FLAGS) $(OBJECTS) -o $(NAME) -L libft/ -lft -L /usr/X11/lib/ \
		-lmlx -lXext -lX11

$(OBJECTS): $(LIB) $(SOURCES) $(HEADERS)
	gcc $(FLAGS) -c $(SOURCES) -I includes/ -I libft/includes/

$(LIB):
	make -C libft/

clean:
	make -C libft/ clean
	rm -f $(OBJECTS)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
