/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:57:33 by naharagu          #+#    #+#             */
/*   Updated: 2022/11/15 20:46:14 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_element(t_info *info, char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'C')
			info->map->cnt_collect++;
		else if (str[i] == 'E')
			info->map->cnt_player++;
		else if (str[i] == 'P')
			info->map->cnt_exit++;
		i++;
	}
}

char	*get_line_in_map(t_info *info, char *file_path)
{
	int		fd;
	char	*str;
	char	*line;
	char	*tmp;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		put_error_and_exit(5);
	str = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '1')
			put_error_and_exit(6);
		validate_map_element(line);
		tmp = str;
		str = ft_strjoin(str, line);
		free(tmp);
		free(line);
		info->map->width++;
	}
	return (str);
}

void	convert_map(t_info *info, char *file_path)
{
	char	*str;
	char	**ret;

	str = get_line_in_map(info, file_path);
	count_element(info, str);
	ret = ft_split(str, '\n');
	info->map->map = ret;
	// printf("map is %s\n", info->map->map[0]);
	printf("C: %d, E: %d, P: %d\n", info->map->cnt_collect, info->map->cnt_exit, info->map->cnt_player);
	free(str);
}
