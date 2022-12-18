/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:33:38 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/15 23:40:34 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// __attribute__((destructor))
// static void destructor() {
// 	system("leaks -q so_long");
// }

void	put_error_and_exit(int error_num)
{
	if (error_num == 1)
		ft_putstr_fd("so_long needs 2 argments", 2);
	else if (error_num == 2)
		ft_putstr_fd("invalid file path", 2);
	else if (error_num == 3)
		ft_putstr_fd("invalid map", 2);
	else if (error_num == 4)
		ft_putstr_fd("image failed", 2);
	else if (error_num == 5)
		ft_putstr_fd("cannot open file", 2);
	else if (error_num == 9)
		ft_putstr_fd("malloc failed", 2);

	exit(EXIT_FAILURE);
}

t_info *init_info(t_info *info)
{
	info = malloc(sizeof(t_info));
	info->map = malloc(sizeof(t_map));
	info->player = malloc(sizeof(t_player));
	info->img_path = malloc(sizeof(char **) * 5);
	if (!info || !info->map || !info->player || !info->img_path)
		put_error_and_exit(9);
	info->cnt_move = 0;
	info->player->x_pos = 0;
	info->player->y_pos = 0;
	info->player->x_exit = 0;
	info->player->y_exit = 0;
	info->map->cnt_collect = 0;
	info->map->cnt_player = 0;
	info->map->cnt_exit = 0;
	info->map->cnt_exit = 0;
	info->map->width = 0;
	info->map->height= 0;
	info->img_path['1'] = "assets/wall.xpm";
	info->img_path['0'] = "assets/floor.xpm";
	info->img_path['P'] = "assets/player.xpm";
	info->img_path['E'] = "assets/exit.xpm";
	info->img_path['C'] = "assets/collect.xpm";
	return (info);
}

void so_long(t_info *info)
{
	mlx_hook(info->mlx_win, E_KEY_PRESS, M_KEY_PRESS, control_player, &info);
	mlx_hook(info->mlx_win, E_WIN_CLOSE, M_WIN_RESIZE, mlx_loop_end, &info);
	mlx_hook(info->mlx_win, E_WIN_RESIZE, M_WIN_CLOSE, get_image, &info);
	mlx_loop(info->mlx);
}

int	main(int argc, char ** argv)
{
	t_info *info;

	if (argc != 2)
		put_error_and_exit(1);
	info = init_info(info);
	convert_map(info, argv[1]);
	validate_map(info);
	get_image(info);
	// get_image(info);
	info->mlx = mlx_init();
	printf("height: %d\n", info->map->height);
	info->mlx_win = mlx_new_window(info->mlx, info->map->height * IMAGE_SIZE, info->map->width * IMAGE_SIZE, "so_long");
	so_long(info);
	return (0);
}

// int	main(void)
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;

// 	mlx_ptr = mlx_init();
// 	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
// 	mlx_loop(mlx_ptr);
// }

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 400, 300, "Hello world!");
// 	img.img = mlx_new_image(mlx, 400, 300);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	my_mlx_pixel_put(&img, 5, 5, 0x0000FF00);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }