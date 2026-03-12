SRCS := init.c builder.c parser.c error.c header.c source.c utils.c exit.c
HDRS := builder.h
NAME := build++

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	cc $(SRCS) -o $(NAME) 

fclean:
	rm -rf $(NAME)

re: fclean all

.Phony: all fclean re