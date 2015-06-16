# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amulin <amulin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/17 11:06:17 by amulin            #+#    #+#              #
#    Updated: 2015/06/10 14:27:16 by amulin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf_v2

CC = clang

STDFLAGS = -Wall -Werror -Wextra

VISUFLAGS = -framework OpenGL -framework AppKit

LIBFLAGS = -Llibft/ -lft -Lminilibx_macos/ -lmlx

SRCS = main_v2.c preliminary.c data_processing.c verbose.c misc.c fdf_draw.c \
	   fdf_draw_2.c fdf_draw_map.c verbose_2.c fdf_calc.c init.c fdf_images.c \
	   fdf_lines.c

SRCDIR = sources/

SOURCES = $(addprefix $(SRCDIR), $(SRCS))

HEADERS = includes/ minilibx_macos/ libft/includes/

INCLUDES = $(addprefix -I, $(HEADERS))

OBJECTS = $(subst .c,.o,$(SRCS))

LIB = libft/libft.a

.PHONY: all, clean, fclean, re

all: $(NAME)
	
$(NAME): $(OBJECTS)
	$(CC) $(STDFLAGS) $(OBJECTS) -o $(NAME) $(LIBFLAGS) $(VISUFLAGS)

$(OBJECTS): $(LIB) $(SOURCES) $(HEADERS)
	$(CC) $(STDFLAGS) -c $(SOURCES) $(INCLUDES)

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
