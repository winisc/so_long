/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 04:41:59 by wini              #+#    #+#             */
/*   Updated: 2025/08/17 01:10:22 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_params(t_map *map)
{
	if (map->count_player != 1)
		return (0);
	if (map->count_exit != 1)
		return (0);
	if (map->count_collectibles < 1)
		return (0);
	return (1);
}

int	ft_check_horizontal_ends(char **grid, size_t width, size_t height)
{
	size_t	i;

	i = 0;
	while (grid[i])
	{
		if (i >= 1 && i <= height - 2)
		{
			if (!(grid[i][0] == '1' && grid[i][width - 1] == '1'))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_walls(char *row)
{
	while (*row)
	{
		if (*row != '1')
			return (0);
		row++;
	}
	return (1);
}

int	ft_check_vertical_ends(char **grid, size_t height)
{
	if (!ft_check_walls (grid[0]))
		return (0);
	if (!ft_check_walls (grid[height - 1]))
		return (0);
	return (1);
}

t_map	*ft_load_map(char *map_file)
{
	int		fd;
	t_map	*map;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = ft_parse_map(fd);
	if (!map)
	{
		printf("(inital check map falid)\n");
		close(fd);
		return (NULL);
	}
	close(fd);
	if (!ft_check_map_params(map))
		return (printf("(check params failed)\n"), ft_free_load_map(map));
	if (!ft_check_vertical_ends(map->grid, map->height))
		return (printf("(check vertical ends failed)\n"), ft_free_load_map(map));
	if (!ft_check_horizontal_ends(map->grid, map->width, map->height))
		return (printf("(check horizontal ends failed)\n"), ft_free_load_map(map));
	if (!ft_check_path(map))
		return (ft_free_load_map(map));
	return (map);
}
