#!/bin/sh

clang -Wall -Werror -Wextra image_management_mlx.c -I ../minilibx_macos/ \
	-I ../libft/includes -L ../libft -L ../minilibx_macos -lmlx -lft \
	-framework OpenGL -framework AppKit -o mlx_image.out
