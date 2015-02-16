

NAME = fdf

FLAGS = -Wall -Werror -Wextra

SRCS = main.c

SRCDIR = sources/

SOURCES = $(addprefix $(SRCDIR), $(SRCS))

OBJECTS = $(subst .c,.o,$(SRCS))

LIB = libft/libft.a

.PHONY: all, clean, fclean, re

all: $(NAME)
	
$(NAME): $(OBJECTS)
	gcc $(FLAGS) $(OBJECTS) -o $(NAME) -L libft/ -lft

$(OBJECTS): $(LIB)
	gcc $(FLAGS) -c $(SOURCES) -I includes/ -I libft/includes/

$(LIB):
	make -C libft/

clean:
	rm -f $(NAME)

fclean: clean
	make -C libft/ fclean
	rm -f $(OBJECTS)

re: fclean all
