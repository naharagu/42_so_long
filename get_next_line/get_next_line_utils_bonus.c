/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:06:01 by naharagu          #+#    #+#             */
/*   Updated: 2022/12/28 23:53:32 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_strchr(const char *s, int c)
{
	char	*dst;

	dst = (char *)s;
	while (1)
	{
		if (*dst == (char)c)
			return (dst);
		if (*dst == '\0')
			break ;
		dst++;
	}
	return (NULL);
}

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 | !s2)
		return (NULL);
	i = gnl_strlen(s1);
	j = gnl_strlen(s2);
	res = malloc((i + j + 1) * sizeof(char));
	if (!res)
		return (NULL);
	gnl_strlcpy(res, s1, i + 1);
	gnl_strlcpy(res + i, s2, j + 1);
	return (res);
}

char	*gnl_strdup(const char *s1)
{
	size_t	len;
	char	*dest;

	len = gnl_strlen(s1);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	gnl_strlcpy(dest, s1, len + 1);
	return (dest);
}
