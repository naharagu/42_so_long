/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:06:42 by naharagu          #+#    #+#             */
/*   Updated: 2022/12/27 17:16:21 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	select_image(t_info *info, char c)
{
	int	height;
	int	width;

	info->mlx_img = mlx_xpm_file_to_image(info->mlx, info->img_path[c], &height,
			&width);
	if (info->mlx_img == NULL)
		put_error_and_exit(4);
}

void	put_image(t_info *info, int x, int y)
{
	x *= IMAGE_SIZE;
	y *= IMAGE_SIZE;
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->mlx_img, x, y);
	mlx_destroy_image(info->mlx, info->mlx_img);
}

int	print_map(t_info *info)
{
	int	x;
	int	y;

	x = 0;
	while (x < info->map->height)
	{
		y = 0;
		while (y < info->map->width)
		{
			select_image(info, info->map->map[x][y]);
			put_image(info, y, x);
			if (info->map->map[x][y] == 'P')
			{
				info->player->x_pos = x;
				info->player->y_pos = y;
			}
			y++;
		}
		x++;
	}
	return (0);
}
