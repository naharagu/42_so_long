/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:28:05 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/15 14:23:48 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_position(t_info *info, size_t x, size_t y)
{
	if (x != info->player->x_pos || y != info->player->y_pos)
		select_image(info, 'P');
	else
		return ;
	put_image(info, info->player->x_pos, info->player->y_pos);
	mlx_destroy_image(info->mlx, info->img->img);
	select_image(info, '0');
	put_image(info, x, y);
	mlx_destroy_image(info->mlx, info->img->img);
	info->map->map[x][y] = '0';
	if (info->map->map[info->player->x_pos][info->player->y_pos] == 'C')
		info->map->cnt_collect--;
	info->map->map[info->player->x_pos][info->player->y_pos] = 'P';
}

int	can_move(t_info *info, char next_position)
{
	if (next_position == 'E')
	{
		if (info->map->cnt_collect == 0)
			mlx_loop_end(info->mlx);
		return (0);
	}
	if (next_position != '1')
	{
		info->cnt_move++;
		ft_putnbr_fd(info->cnt_move, 1);
		ft_putchar_fd('\n', 1);
		return (1);
	}
	return (0);
}

int	control_player(int key, t_info *info)
{
	size_t	x_tmp;
	size_t	y_tmp;

	x_tmp = info->player->x_pos;
	y_tmp = info->player->y_pos;
	if (key == ESC)
		mlx_loop_end(info->mlx);
	if (key == W)
		info->player->y_pos--;
	else if (key == S)
		info->player->y_pos++;
	else if (key == A)
		info->player->y_pos--;
	else if (key == D)
		info->player->y_pos++;
	else
		return (0);
	if (can_move(info, info->map->map[info->player->x_pos][info->player->y_pos]))
		update_position(info, x_tmp, y_tmp);
	else
	{
		info->player->x_pos = x_tmp;
		info->player->x_exit = y_tmp;
	}
	return (0);
}

// int	close_window(t_info *info)
// {
// 	mlx_loop_end(info->mlx);
// 	return (0);
// }

// int	minimize_window(t_info *info)
// {
// 	get_image(info);
// 	return (0);
// }
