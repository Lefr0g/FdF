# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amulin <amulin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/17 11:06:17 by amulin            #+#    #+#              #
#    Updated: 2015/07/01 18:32:21 by amulin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = clang

STDFLAGS = -Wall -Werror -Wextra

VISUFLAGS = -framework OpenGL -framework AppKit

LIBFLAGS = -Llibft/ -lft -Lminilibx_macos/ -lmlx

SRCS = main.c fdf_preliminary.c fdf_data_processing.c fdf_verbose_1.c \
	   fdf_verbose_2.c fdf_init.c fdf_set.c fdf_draw_loop.c \
	   fdf_draw_textframes.c fdf_draw_colorpix.c fdf_draw_map.c fdf_images.c \
	   fdf_calc_1.c fdf_calc_2.c fdf_lines.c fdf_keys.c fdf_misc.c \
	   fdf_ending.c

SRCDIR = sources/

SOURCES = $(addprefix $(SRCDIR), $(SRCS))

HEADERS = includes/ minilibx_macos/ libft/includes/

INCLUDES = $(addprefix -I, $(HEADERS))

OBJECTS = $(subst .c,.o,$(SRCS))

LIB = libft/libft.a

.PHONY: all, clean, fclean, re

all: libs $(NAME)
	
$(NAME): $(OBJECTS)
	$(CC) $(STDFLAGS) $(OBJECTS) -o $(NAME) $(LIBFLAGS) $(VISUFLAGS)

$(OBJECTS): $(LIB) $(SOURCES) $(HEADERS)
	$(CC) $(STDFLAGS) -c $(SOURCES) $(INCLUDES)

$(LIB) : libs

libs:
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
