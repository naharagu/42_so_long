/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:33:38 by naharagu          #+#    #+#             */
/*   Updated: 2022/12/30 18:20:43 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(t_info *info)
{
	info->mlx = mlx_init();
	info->mlx_win = mlx_new_window(info->mlx, info->map->width * IMAGE_SIZE,
			info->map->height * IMAGE_SIZE, "so_long");
	print_map(info);
	mlx_key_hook(info->mlx_win, control_player, info);
	mlx_hook(info->mlx_win, WIN_CLOSE, 1L << 2, close_window, info);
	mlx_hook(info->mlx_win, WIN_RESIZE, 1L << 2, print_map, info);
	mlx_expose_hook(info->mlx_win, print_map, info);
	mlx_loop(info->mlx);
	free_all(info);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 2)
		put_error_and_exit(1);
	info = init_info(info);
	convert_map(info, argv[1]);
	validate_map(info);
	so_long(info);
	return (0);
}
