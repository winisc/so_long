/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_erros.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:51:28 by wini              #+#    #+#             */
/*   Updated: 2025/08/17 02:00:26 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_grid(char **grid)
{
	size_t	i;

	i = 0;
	while (grid && grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	*ft_free_load_map(t_map *map)
{
	if (!map)
		return (NULL);
	if (!map->grid)
	{
		free (map);
		map = NULL;
		return (NULL);
	}
	ft_free_grid(map->grid);
	free (map);
	map = NULL;
	return (NULL);
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
