/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:36:25 by naharagu          #+#    #+#             */
/*   Updated: 2022/12/27 12:32:13 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_element(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C' && \
			str[i] != 'E' && str[i] != 'P')
			put_error_and_exit(3);
		i++;
	}
	return (0);
}

int	up_and_down_frame(t_info *info)
{
	size_t	x;
	size_t	y;

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

int	side_frame(t_info *info)
{
	size_t	x;
	size_t	y;

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

int	compare_length(t_info *info)
{
	size_t	i;
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
	compare_length(info);
	up_and_down_frame(info);
	// side_frame(info);
	// ft_putstr_fd("hi!\n", 1);
	return (0);
}
