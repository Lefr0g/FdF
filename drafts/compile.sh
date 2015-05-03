#!/bin/sh

gcc -Wall -Werror -Wextra my_print_loadbar.c -I ../libft/includes -I ../includes -L ../libft -lft
