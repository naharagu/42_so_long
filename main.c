/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:33:38 by naharagu          #+#    #+#             */
/*   Updated: 2022/12/27 12:05:46 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// __attribute__((destructor))
// static void destructor() {
// 	system("leaks -q so_long");
// }

void so_long(t_info *info)
{
	printf("start sl: xpos %d, ypos is %d\n", info->player->x_pos, info->player->y_pos);
	// mlx_key_hook(info->mlx, control_player, &info);
	mlx_hook(info->mlx_win, E_KEY_PRESS, M_KEY_PRESS, control_player, &info);
	// mlx_hook(info->mlx_win, E_WIN_CLOSE, M_WIN_RESIZE, mlx_loop_end, &info);
	// mlx_hook(info->mlx_win, E_WIN_RESIZE, M_WIN_CLOSE, get_image, &info);
	mlx_loop(info->mlx);
	free_all(info, info->map->height);
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
	print_map(info);
	// printf("height: %d\n", info->map->height);
	so_long(info);
	return (0);
}
