CC			=	gcc
C_FLAGS 	=	-Wall -Werror -Wextra
MLX_DIR		= 	./minilibx-linux
MIX_FLAGS	=	-L$(MLX_DIR)/libmlx.a -lmlx -lXext -lX11
SRCS		= 	main.c

NAME	=	so_long

OBJS	=	${SRCS:%.c=%.o}

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(C_FLAGS) $(OBJS)  -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX_DIR)/libmlx.a

re: fclean all

.PHONY: all clean fclean re
