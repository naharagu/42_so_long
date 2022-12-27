/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:36:25 by naharagu          #+#    #+#             */
/*   Updated: 2022/12/27 19:19:18 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char**	find_e_p(t_info *info)
{
	int	x;
	int	y;
	char ** tmp;

	x = 0;
	tmp = malloc(sizeof(char**));
	while (x < info->map->height)
	{
		y = 0;
		tmp[x][y] = info->map->map[x][y];
		while (y < info->map->width)
		{

			if (info->map->map[x][y] == 'P')
			{
				info->player->x_pos = x;
				info->player->y_pos = y;
			}
			if (info->map->map[x][y] == 'E')
			{
				info->player->x_exit = x;
				info->player->y_exit = y;
			}
			y++;
		}
		x++;
	}
	return (tmp);
}

int dfs(int x, int y, t_info *info, char **tmp)
{
	char c;

	if (x == info->player->x_exit && y == info->player->y_exit)
		return 1;
	c = info->map->map[x][y];
	if (c == '1')
		return 0;
	if (c == '10')
		return 0;
	info->map->map[x][y] = '10';
	dfs(x, y + 1, info);
	dfs(x + 1, y, info);
	dfs(x, y - 1, info);
	dfs(x - 1, y, info);
}

int	validate_path(t_info *info)
{
	char ** tmp;
	int x;
	int y;

	x = info->player->x_exit;
	y = info->player->y_exit;
	tmp = find_e_p(info);
	x = dfs(x, y, info, tmp);
	printf("dfs: %d\n", x);
	free(tmp);
	return (0);
}
