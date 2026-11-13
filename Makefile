NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_parser.c ft_parser_utils.c ft_split.c utils.c m.c create_stack.c\
       op_print.c op_puw.c op_rotate.c op_reverse.c alg_simple.c ft_memmove.c alg_alenya.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
