/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsilveir <wsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:27:06 by wsilveir          #+#    #+#             */
/*   Updated: 2025/08/23 17:29:13 by wsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fill_path(char **grid, t_map *map, size_t px, size_t py)
{
	if (py >= (map->height - 1) || px >= (map->width - 1))
		return ;
	if (grid[py][px] == '1' || grid[py][px] == 'F')
		return ;
	if (grid[py][px] == 'E')
	{	
		grid[py][px] = 'F';
		return ;
	}
	grid[py][px] = 'F';
	if (px > 0)
		ft_fill_path(grid, map, px - 1, py);
	ft_fill_path(grid, map, px + 1, py);
	if (py > 0)
		ft_fill_path(grid, map, px, py - 1);
	ft_fill_path(grid, map, px, py + 1);
}

char	**ft_copy_grid(char **grid)
{
	size_t	i;
	char	**copy;

	i = 0;
	while (grid[i])
		i++;
	copy = malloc((i + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (grid[i])
	{
		copy[i] = ft_strdup(grid[i]);
		if (!copy[i])
		{
			ft_free_grid(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	ft_find_player(t_map *map, size_t *px, size_t *py)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == 'P')
			{
				*px = x;
				*py = y;
				map->px = x;
				map->py = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	ft_check_collectibles_and_exit(char **grid)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'C' || grid[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_check_path(t_map *map)
{
	size_t	player_pos_x;
	size_t	player_pos_y;
	char	**copy_grid;

	ft_find_player(map, &player_pos_x, &player_pos_y);
	copy_grid = ft_copy_grid(map->grid);
	if (!copy_grid)
	{
		ft_putendl_fd("Error: Failed to copy map grid", 2);
		return (0);
	}
	ft_fill_path(copy_grid, map, player_pos_x, player_pos_y);
	if (!ft_check_collectibles_and_exit(copy_grid))
	{
		ft_free_grid(copy_grid);
		return (0);
	}
	ft_free_grid(copy_grid);
	return (1);
}
