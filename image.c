/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:06:42 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/15 19:56:43 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	select_image(t_info *info, char c)
{
	info->img->img = mlx_xpm_file_to_image(info->mlx, info->img->path[c], \
		&info->img->height, &info->img->width);
	if (info->img->img == NULL)
		put_error_and_exit(4);
}

void	put_image(t_info *info, size_t x, size_t y)
{
	x *= IMAGE_SIZE;
	y *= IMAGE_SIZE;
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->img->img, x, y);
}

int	get_image(t_info *info)
{
	size_t	y;
	size_t	x;

	x = 0;
	while (x < info->map->height)
	{
		y = 0;
		while (y < info->map->width)
		{
			printf("now: %c\n", info->map->map[x][y]);
			select_image(info, info->map->map[x][y]);
			put_image(info, x, y);
			mlx_destroy_image(info->mlx, info->img->img);
			if (info->map->map[x][y] == 'P')
			{
				info->player->x_exit = x;
				info->player->x_exit = y;
			}
			y++;
		}
		x++;
	}
	return (0);
}
