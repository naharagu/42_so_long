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

void	update_position(t_info *info, size_t x, size_t y)
{
	printf("update: x is %zu, y is %zu\n", x, y);
	if (x == info->player->x_pos && y == info->player->y_pos)
		return ;
	printf("test2\n");
	select_image(info, 'P');
	put_image(info, info->player->x_pos, info->player->y_pos);
	mlx_destroy_image(info->mlx, info->mlx_img);
	select_image(info, '0');
	put_image(info, x, y);
	mlx_destroy_image(info->mlx, info->mlx_img);
	info->map->map[x][y] = '0';
	if (info->map->map[info->player->x_pos][info->player->y_pos] == 'C')
		info->map->cnt_collect--;
	info->map->map[info->player->x_pos][info->player->y_pos] = 'P';
}

int	can_move(t_info *info, char next_position)
{
	printf("canmove: x is %zu, y is %zu\n", info->player->x_pos, info->player->y_pos);
	if (next_position == 'E')
	{
		if (info->map->cnt_collect == 0)
			mlx_loop_end(info->mlx);
		return (0);
	}
	if (next_position != '1')
	{
		info->cnt_move++;
		ft_printf("move count: %zu\n", info->cnt_move);
		return (1);
	}
	return (0);
}

int	control_player(int key, t_info *info)
{
	if (key == ESC)
		mlx_loop_end(info->mlx);
	if (key == W)
		info->player->y_pos -= 1;
	else if (key == S)
		info->player->y_pos += 1;
	else if (key == A)
		info->player->x_pos -= 1;
	else if (key == D)
		info->player->x_pos += 1;
	else
		return (0);
}

// int	control_player(int key, t_info *info)
// {
// 	int x_tmp;
// 	int	y_tmp;

// 	printf("start cl: x %d, y %d\n", info->player->x_pos, info->player->y_pos);

// 	x_tmp = info->player->x_pos;
// 	y_tmp = info->player->y_pos;

// 	printf("key is %d\n", key);
// 	printf("xtmpis %d, ytmp is %d\n", x_tmp, y_tmp);

// 	if (key == ESC)
// 		mlx_loop_end(info->mlx);
// 	if (key == W)
// 		info->player->y_pos -= 1;
// 	else if (key == S)
// 		info->player->y_pos += 1;
// 	else if (key == A)
// 		info->player->x_pos -= 1;
// 	else if (key == D)
// 		info->player->x_pos += 1;
// 	else
// 		return (0);
// 	// printf("x is %zu, y is %zu\n", x_tmp, y_tmp);
// 	printf("tmp2 xpos %d, ypos is %d\n", info->player->x_pos, info->player->y_pos);
// 	if (can_move(info, info->map->map[info->player->x_pos][info->player->y_pos]))
// 		update_position(info, x_tmp, y_tmp);
// 	else
// 	{
// 		printf("set x t0 %d, y to %d\n", x_tmp, y_tmp);
// 		info->player->x_pos = x_tmp;
// 		info->player->y_exit = y_tmp;
// 	}
// 	return (0);
// }
