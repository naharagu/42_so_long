/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:36:25 by naharagu          #+#    #+#             */
/*   Updated: 2023/01/19 21:29:26 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_row_frame(t_info *info)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (info->map->map[x][y] != '\0')
	{
		if (info->map->map[x][y] != '1')
			put_error_and_exit(3);
		y++;
	}
	y = 0;
	x = info->map->height - 1;
	while (info->map->map[x][y] != '\0')
	{
		if (info->map->map[x][y] != '1')
			put_error_and_exit(3);
		y++;
	}
	return (0);
}

int	validate_side_frame(t_info *info)
{
	int	x;
	int	y;

	x = 1;
	while (x < info->map->height - 1)
	{
		y = 0;
		while (y < info->map->width)
		{
			if (y == 0 || y == info->map->width - 1)
			{
				if (info->map->map[x][y] != '1')
					put_error_and_exit(3);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int	validate_length(t_info *info)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(info->map->map[i]);
	while (i < info->map->height)
	{
		if (len != ft_strlen(info->map->map[i]))
			put_error_and_exit(3);
		i++;
	}
	info->map->width = len;
	return (0);
}

int	validate_map(t_info *info)
{
	if (info->map->cnt_collect < 1 || \
		info->map->cnt_player != 1 || \
		info->map->cnt_exit != 1)
		put_error_and_exit(3);
	validate_length(info);
	validate_row_frame(info);
	validate_side_frame(info);
	validate_path(info);
	return (0);
}
