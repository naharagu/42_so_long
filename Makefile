CC			=	gcc
C_FLAGS 	=	-Wall -Werror -Wextra -g -fsanitize=address
MLX_DIR		= ./minilibx-linux
LIB_DIR		= ./libft
GNL_DIR		= ./get_next_line
SRCS		= 	main.c \
				check_error.c \
				hook_helper.c \
				convert_map.c \
				image.c

NAME	=	so_long

OBJS	=	${SRCS:%.c=%.o}

os = $(shell uname)

ifeq ($(os), Darwin)
	MLX_FLAGS = minilibx-linux/libmlx.a -L/usr/X11R6/lib -lX11 -lXext #-fsanitize=address
else
	MLX_FLAGS = minilibx-linux/libmlx.a -lXext -lX11 -lm
endif
#MLX_FLAGS	=	-L/usr/X11/lib -lmlx -lXext -lX11
LIB		= ./libft/libft.a
GNL	= ./get_next_line/get_next_line.a

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	make -C $(LIB_DIR)
	make -C $(GNL_DIR)
	$(CC) $(C_FLAGS) $(OBJS)  -o $(NAME) $(MLX_FLAGS) $(LIB) $(GNL)

all: $(NAME)

clean:
	make -C $(MLX_DIR)
	make -C $(LIB_DIR)
	make -C $(GNL_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX_DIR)/libmlx.a
	rm -f $(LIB_DIR)/libft.a
	rm -f $(GNL_DIR)/get_next_line.a

re: fclean all

.PHONY: all clean fclean re
