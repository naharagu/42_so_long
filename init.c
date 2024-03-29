/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:03:29 by naharagu          #+#    #+#             */
/*   Updated: 2022/12/31 17:13:40 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_info	*init_info(t_info *info)
{
	info = malloc(sizeof(t_info));
	if (!info)
		put_error_and_exit(9);
	info->map = malloc(sizeof(t_map));
	if (!info->map)
		put_error_and_exit(9);
	info->player = malloc(sizeof(t_player));
	if (!info->player)
		put_error_and_exit(9);
	info->cnt_move = 0;
	info->player->x_pos = 0;
	info->player->y_pos = 0;
	info->player->x_exit = 0;
	info->player->y_exit = 0;
	info->map->cnt_collect = 0;
	info->map->cnt_player = 0;
	info->map->cnt_exit = 0;
	info->map->cnt_exit = 0;
	info->map->width = 0;
	info->map->height = 0;
	return (info);
}
