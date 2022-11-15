CC = gcc
CFLAGS   = -Wall -Wextra -Werror
SRCS    = 	get_next_line_bonus.c \
			get_next_line_utils_bonus.c
NAME		= get_next_line.a

OBJS		= ${SRCS:%.c=%.o}

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re bonus
