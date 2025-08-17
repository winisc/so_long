/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsilveir <wsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:40:05 by wsilveir          #+#    #+#             */
/*   Updated: 2025/08/16 23:02:07 by wsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_width_len(char *row)
{
	size_t	len;

	len = 0;
	while (row[len])
	{
		if (row[len] == '\n')
			return (len);
		len++;
	}
	return (len);
}

void	*ft_free_map_file(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (NULL);
}

void	ft_start_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->count_collectibles = 0;
	map->count_player = 0;
	map->count_exit = 0;
	map->grid = NULL;
}

void	*ft_free_load_map(t_map *map)
{
	size_t	i;

	if (!map)
		return (NULL);
	if (!map->grid)
	{
		free (map);
		map = NULL;
		return (NULL);
	}
	i = 0;
	while (map->grid[i])
	{
		free(map->grid[i]);
		i++;
	}
	free (map->grid);
	free (map);
	map = NULL;
	return (NULL);
}

char	*ft_strdup_nl(const char *src)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (src[len - 1] != '\n')
		len = len + 1;
	str = (char *)malloc(len * sizeof(char));
	i = 0;
	if (!str)
		return (NULL);
	while (src[i] != '\n' && src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
