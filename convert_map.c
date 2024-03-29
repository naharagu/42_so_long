/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:57:33 by naharagu          #+#    #+#             */
/*   Updated: 2022/12/30 18:38:37 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_filename(char *file_path)
{
	size_t	len;

	len = ft_strlen(file_path);
	if (len <= 4)
		return (-1);
	if (ft_strncmp(file_path + len - 4, ".ber", 4))
		return (-1);
	return (0);
}

void	validate_map_element(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'C' && \
			str[i] != 'E' && str[i] != 'P')
			put_error_and_exit(3);
		i++;
	}
	return ;
}

void	count_element(t_info *info, char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'C')
			info->map->cnt_collect++;
		else if (str[i] == 'P')
			info->map->cnt_player++;
		else if (str[i] == 'E')
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
			put_error_and_exit(3);
		validate_map_element(line);
		tmp = str;
		str = ft_strjoin(str, line);
		free(tmp);
		free(line);
		info->map->height++;
	}
	return (str);
}

void	convert_map(t_info *info, char *file_path)
{
	char	*str;
	char	**ret;

	if (check_filename(file_path) == -1)
		put_error_and_exit(2);
	str = get_line_in_map(info, file_path);
	count_element(info, str);
	ret = ft_split(str, '\n');
	info->map->map = ret;
	free(str);
}
