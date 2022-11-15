/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:39:02 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/15 20:45:23 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "get_next_line/get_next_line_bonus.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <fcntl.h>

# define E_KEY_PRESS 2
# define E_WIN_RESIZE 9
# define E_WIN_CLOSE 17

# define M_KEY_PRESS 1
# define M_WIN_RESIZE 2097152
# define M_WIN_CLOSE 131072

# define IMAGE_SIZE 16

# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307

typedef struct s_img
{
	char **path;
	void *img;
	int	height;
	int	width;
}				t_img;

typedef struct s_map
{
	char **map;
	int	cnt_collect;
	int	cnt_player;
	int	cnt_exit;
	int	height;
	int	width;
}				t_map;

typedef struct s_player
{
	int	x_pos;
	int	y_pos;
	int	x_exit;
	int	y_exit;
}				t_player;

typedef struct s_info
{
	void	*mlx;
	void	*mlx_win;
	size_t	cnt_move;
	t_player *player;
	t_map		*map;
	t_img		*img;
}				t_info;

int	control_player(int key, t_info *info);
void	put_error_and_exit(int error_num);
void	convert_map(t_info *info, char *file_path);
void	select_image(t_info *info, char c);
int	get_image(t_info *info);
void	put_image(t_info *info, size_t x, size_t y);
int	validate_map(t_info *info);
int	validate_map_element(char *str);

#endif