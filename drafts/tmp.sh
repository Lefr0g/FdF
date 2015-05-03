#!/bin/sh

clang -Wall -Werror -Wextra tmp.c -I ../libft/includes -I ../includes -L ../libft -lft -o b.out
