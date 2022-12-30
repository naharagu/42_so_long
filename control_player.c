/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:28:05 by naharagu          #+#    #+#             */
/*   Updated: 2022/12/30 18:05:11 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_position(t_info *info, int x, int y)
{
	if (info->map->map[info->player->x_pos + x][info->player->y_pos + y] == '1')
		return ;
	if (info->map->map[info->player->x_pos + x][info->player->y_pos + y] == 'C')
		info->map->cnt_collect--;
	if (info->map->map[info->player->x_pos + x][info->player->y_pos + y] == 'E')
	{
		if (info->map->cnt_collect == 0)
		{
			ft_putstr_fd("!GOAL!\n", 1);
			mlx_loop_end(info->mlx);
		}
		return ;
	}
	info->map->map[info->player->x_pos][info->player->y_pos] = '0';
	select_image(info, '0');
	put_image(info, info->player->y_pos, info->player->x_pos);
	info->player->x_pos += x;
	info->player->y_pos += y;
	info->map->map[info->player->x_pos][info->player->y_pos] = 'P';
	select_image(info, 'P');
	put_image(info, info->player->y_pos, info->player->x_pos);
	info->cnt_move++;
	ft_putnbr_fd(info->cnt_move, 1);
	ft_putchar_fd('\n', 1);
}

int	control_player(int key, t_info *info)
{
	if (key == ESC)
		mlx_loop_end(info->mlx);
	if (key == W || key == UP)
		move_position(info, -1, 0);
	else if (key == S || key == DOWN)
		move_position(info, 1, 0);
	else if (key == A || key == LEFT)
		move_position(info, 0, -1);
	else if (key == D || key == RIGHT)
		move_position(info, 0, 1);
	return (0);
}
