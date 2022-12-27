/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:03:29 by naharagu          #+#    #+#             */
/*   Updated: 2022/12/27 12:03:39 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_info *init_info(t_info *info)
{
	info = malloc(sizeof(t_info));
	info->map = malloc(sizeof(t_map));
	info->player = malloc(sizeof(t_player));
	info->img_path = malloc(sizeof(char **) * 5);
	if (!info || !info->map || !info->player || !info->img_path)
		put_error_and_exit(9);
	info->cnt_move = 0;
	// info->player->x_pos = malloc(sizeof(int));
	// info->player->y_pos = malloc(sizeof(int));
	info->player->x_pos = 0;
	info->player->y_pos = 0;
	info->player->x_exit = 0;
	info->player->y_exit = 0;
	info->map->cnt_collect = 0;
	info->map->cnt_player = 0;
	info->map->cnt_exit = 0;
	info->map->cnt_exit = 0;
	info->map->width = 0;
	info->map->height= 0;
	info->img_path['1'] = "assets/wall.xpm";
	info->img_path['0'] = "assets/floor.xpm";
	info->img_path['P'] = "assets/player.xpm";
	info->img_path['E'] = "assets/exit.xpm";
	info->img_path['C'] = "assets/collect.xpm";
	return (info);
}