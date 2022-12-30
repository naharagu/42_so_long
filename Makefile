CC			=	gcc
C_FLAGS 	=	-Wall -Werror -Wextra
MLX_DIR		= 	./minilibx
LIB_DIR		= 	./libft
GNL_DIR		= 	./get_next_line
SRCS		= 	main.c \
				init.c \
				validate_map.c \
				validate_path.c \
				convert_map.c \
				image.c \
				control_player.c \
				exit.c
NAME		=	so_long
OBJS_DIR	=	./obj/
OBJS		=	$(SRCS:%.c=$(OBJS_DIR)%.o)
LIB			=	./libft/libft.a
GNL			=	./get_next_line/get_next_line.a

UNAME = $(shell uname)

ifeq ($(UNAME), Darwin)
	MLX_FLAGS = minilibx/libmlx.a -L/usr/X11R6/lib -lX11 -lXext #-fsanitize=address
else
	MLX_FLAGS = minilibx/libmlx.a -lXext -lX11 -lm
endif

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	make -C $(LIB_DIR)
	make -C $(GNL_DIR)
	$(CC) $(C_FLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS) $(LIB) $(GNL)

$(OBJS_DIR)%.o: %.c
		mkdir -p $(OBJS_DIR)
		$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

clean:
	make -C $(MLX_DIR) clean
	make -C $(LIB_DIR) clean
	make -C $(GNL_DIR) clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX_DIR)/libmlx.a
	rm -f $(LIB_DIR)/libft.a
	rm -f $(GNL_DIR)/get_next_line.a

re: fclean all

.PHONY: all clean fclean re
