CC			=	gcc
C_FLAGS 	=	-Wall -Werror -Wextra
MLX_DIR		= ./minilibx-linux
#MLX_FLAGS	=	-L/usr/X11/lib -lmlx -lXext -lX11
MLX_FLAGS	=	minilibx-linux/libmlx.a -lXext -lX11 -lm
SRCS		= 	main.c

NAME	=	so_long

OBJS	=	${SRCS:%.c=%.o}

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(C_FLAGS) $(OBJS)  -o $(NAME) $(MLX_FLAGS)

all: $(NAME)

clean:
	make -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX_DIR)/libmlx.a

re: fclean all

.PHONY: all clean fclean re
