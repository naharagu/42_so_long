/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:06:57 by naharagu          #+#    #+#             */
/*   Updated: 2022/12/30 18:14:59 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_error_and_exit(int error_num)
{
	if (error_num == 1)
		ft_putstr_fd("so_long needs 2 argments\n", 2);
	else if (error_num == 2)
		ft_putstr_fd("invalid file path\n", 2);
	else if (error_num == 3)
		ft_putstr_fd("invalid map\n", 2);
	else if (error_num == 4)
		ft_putstr_fd("image failed\n", 2);
	else if (error_num == 5)
		ft_putstr_fd("cannot open file\n", 2);
	else if (error_num == 9)
		ft_putstr_fd("malloc failed\n", 2);
	exit(EXIT_FAILURE);
}

void	close_window(t_info *info)
{
	mlx_loop_end(info->mlx);
	free_all(info);
	exit(EXIT_SUCCESS);
}

void	free_all(t_info *info)
{
	int	i;

	i = 0;
	while (info->map->map[i])
	{
		free(info->map->map[i]);
		i++;
	}
	free(info->map->map);
	free(info->map);
	free(info->player);
	mlx_clear_window(info->mlx, info->mlx_win);
	mlx_destroy_window(info->mlx, info->mlx_win);
	mlx_destroy_display(info->mlx);
	free(info->mlx);
	free(info);
}
