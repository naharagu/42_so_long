/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:33:38 by naharagu          #+#    #+#             */
/*   Updated: 2022/12/26 16:18:26 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// __attribute__((destructor))
// static void destructor() {
// 	system("leaks -q so_long");
// }

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
	// mlx_hook(info->mlx_win, E_WIN_RESIZE, M_WIN_CLOSE, get_image, &info);
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
	info->mlx = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx, info->map->width * IMAGE_SIZE, info->map->height * IMAGE_SIZE, "so_long");
	get_image(info);
	// printf("height: %d\n", info->map->height);
	so_long(info);
	return (0);
}
