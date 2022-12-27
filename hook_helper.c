/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:28:05 by naharagu          #+#    #+#             */
/*   Updated: 2022/12/26 17:27:16by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_position(t_info *info, int x, int y)
{
	// if (info->map->cnt_collect == 0)
	// 	info->map->map[info->player->x_exit][info->player->y_exit] = 'O';
	printf("now: x %d, y %d\n", info->player->x_pos, info->player->y_pos);
	printf("next is %c\n", info->map->map[info->player->x_pos + x][info->player->y_pos + y]);
	if (info->map->map[info->player->x_pos + x][info->player->y_pos + y] == '1')
		return ;
	if (info->map->map[info->player->x_pos + x][info->player->y_pos + y] == 'C')
		info->map->cnt_collect--;
	info->map->map[info->player->x_pos][info->player->y_pos] = '0';
	select_image(info, '0');
	put_image(info, info->player->y_pos, info->player->x_pos);
	info->player->x_pos += x;
	info->player->y_pos += y;
	info->map->map[info->player->x_pos][info->player->y_pos] = 'P';
	select_image(info, 'P');
	put_image(info, info->player->y_pos, info->player->x_pos);
}

// int	can_move(t_info *info, char next_position)
// {
// 	printf("canmove: x is %d, y is %d\n", info->player->x_pos, info->player->y_pos);
// 	printf("next is %c\n", next_position);
// 	if (next_position == 'E')
// 	{
// 		if (info->map->cnt_collect == 0)
// 			mlx_loop_end(info->mlx);
// 		return (0);
// 	}
// 	if (next_position != '1')
// 	{
// 		info->cnt_move++;
// 		ft_putnbr_fd(info->cnt_move, 1);
// 		ft_putchar_fd('\n', 1);
// 		return (1);
// 	}
// 	return (0);
// }

int	control_player(int key, t_info *info)
{
	printf("\nkey is %d\n", key);

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
