/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:36:25 by naharagu          #+#    #+#             */
/*   Updated: 2022/12/28 21:53:53 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_info *info, char **tmp)
{
	int	x;
	int	y;

	x = 0;
	while (x < info->map->height)
	{
		y = 0;
		while (y < info->map->width)
		{
			tmp[x][y] = info->map->map[x][y];
			// printf("x %d y %d is %c\n", x, y, tmp[x][y]);
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

void	dfs(int x, int y, t_info *info, char **tmp)
{
	char	c;

	if (x < 1 || x > info->map->height - 2 || \
		y < 1 || y > info->map->width - 2)
		return;
	c = tmp[x][y];
	if (c == '1' || c == 'V')
		return ;
	else if (c == '0' || c == 'C' || c == 'E')
		tmp[x][y] = 'V';
	// printf("x %d y %d is %c\n", x, y, c);
	dfs(x, y + 1, info, tmp);
	dfs(x, y - 1, info, tmp);
	dfs(x + 1, y, info, tmp);
	dfs(x - 1, y, info, tmp);
}

int	find_e_c(t_info *info, char **tmp)
{
	int	x;
	int	y;

	x = 0;
	while (x < info->map->height)
	{
		y = 0;
		while (y < info->map->width)
		{
			if (tmp[x][y] == 'E' || tmp[x][y] == 'C')
				return (-1);
			y++;
		}
		x++;
	}
	return (0);
}

int	validate_path(t_info *info)
{
	char	**tmp;
	int		i;
	int		x;
	int		y;

	tmp = malloc(sizeof(char *) * (info->map->height + 1));
	i = 0;
	while (i < info->map->height)
	{
		tmp[i] = malloc(sizeof(char) * (info->map->width + 1));
		i++;
	}
	tmp = copy_map(info, tmp);
	x = info->player->x_pos;
	y = info->player->y_pos;
	dfs(x, y, info, tmp);

	// x = 0;
	// while (x < info->map->height)
	// {
	// 	y = 0;
	// 	while (y < info->map->width)
	// 	{
	// 		printf("%c", tmp[x][y]);
	// 		if (y == info->map->width - 1)
	// 			printf("\n");
	// 		y++;
	// 	}
	// 	x++;
	// }

	if (find_e_c(info, tmp) == -1)
		put_error_and_exit(3);
	i = 0;
	while (i < info->map->height)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	return (0);
}
