SRCS := src/init.c src/builder.c src/parser.c src/error.c src/header.c src/source.c src/utils.c src/exit.c
HDRS := includes/builder.h
NAME := build++
FLAGS := -Wall -Wextra -Werror -I./includes

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	cc $(FLAGS) $(SRCS) -o $(NAME) 

fclean:
	rm -rf $(NAME)

re: fclean all

.Phony: all fclean re