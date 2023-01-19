/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:06:42 by naharagu          #+#    #+#             */
/*   Updated: 2023/01/19 21:30:14 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	select_image(t_info *info, char c)
{
	int		height;
	int		width;
	char	*img_path;

	if (c == '1')
		img_path = "./assets/wall.xpm";
	else if (c == '0')
		img_path = "./assets/floor.xpm";
	else if (c == 'P')
		img_path = "./assets/player.xpm";
	else if (c == 'E')
		img_path = "./assets/exit.xpm";
	else
		img_path = "./assets/collect.xpm";
	info->mlx_img = mlx_xpm_file_to_image(info->mlx, img_path, &height, &width);
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
