SRCS := init.c builder.c parser.c error.c header.c source.c utils.c
HDRS := builder.h
NAME := Builder++

all: $(NAME)

$(NAME): $(SRCS) $(HDRS)
	cc $(SRCS) -o $(NAME) 

fclean:
	rm -rf $(NAME)

re: fclean all

.Phony: all fclean re