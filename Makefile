# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amulin <amulin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/17 11:06:17 by amulin            #+#    #+#              #
#    Updated: 2015/03/27 15:17:10 by amulin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

STDFLAGS = -Wall -Werror -Wextra

VISUFLAGS = -framework OpenGL -framework AppKit

LIBFLAGS = -Llibft/ -lft -Lminilibx_macos/ -lmlx

SRCS = main.c

SRCDIR = sources/

SOURCES = $(addprefix $(SRCDIR), $(SRCS))

HEADERS = includes/ minilibx_macos/ libft/includes/

INCLUDES = $(addprefix -I, $(HEADERS))

OBJECTS = $(subst .c,.o,$(SRCS))

LIB = libft/libft.a

.PHONY: all, clean, fclean, re

all: $(NAME)
	
$(NAME): $(OBJECTS)
	gcc $(STDFLAGS) $(OBJECTS) -o $(NAME) $(LIBFLAGS) $(VISUFLAGS)

$(OBJECTS): $(LIB) $(SOURCES) $(HEADERS)
	gcc $(STDFLAGS) -c $(SOURCES) $(INCLUDES)

$(LIB):
	make -C libft/
	make -C minilibx_macos/

clean:
	make -C libft/ clean
	rm -f $(OBJECTS)

fclean: clean
	make -C libft/ fclean
	make -C minilibx_macos/ clean
	rm -f $(NAME)

re: fclean all
