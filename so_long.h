/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:39:02 by naharagu          #+#    #+#             */
/*   Updated: 2022/12/28 22:33:12 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line_bonus.h"
# include "libft/ft_printf.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define E_KEY_PRESS 2
# define E_WIN_RESIZE 9
# define E_WIN_CLOSE 17

# define IMAGE_SIZE 32

# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

typedef struct s_map
{
	char		**map;
	char		**map_check;
	int			cnt_collect;
	int			cnt_player;
	int			cnt_exit;
	int			height;
	int			width;
}				t_map;

typedef struct s_player
{
	int			x_pos;
	int			y_pos;
	int			x_exit;
	int			y_exit;
}				t_player;

typedef struct s_info
{
	void		*mlx;
	void		*mlx_win;
	size_t		cnt_move;
	t_player	*player;
	t_map		*map;
	char		**img_path;
	void		*mlx_img;
}				t_info;

t_info			*init_info(t_info *info);
int				control_player(int key, t_info *info);
void			put_error_and_exit(int error_num);
void			convert_map(t_info *info, char *file_path);
void			select_image(t_info *info, char c);
int				print_map(t_info *info);
void			put_image(t_info *info, int x, int y);
int				validate_map(t_info *info);
int				validate_path(t_info *info);
void			free_all(t_info *info);

#endif
