/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path_map_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsilveir <wsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:27:06 by wsilveir          #+#    #+#             */
/*   Updated: 2025/08/25 20:27:36 by wsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_fill_path(char **grid, t_map *map, size_t player_x, size_t player_y)
{
	if (player_y >= (map->height - 1) || player_x >= (map->width - 1))
		return ;
	if (grid[player_y][player_x] == '1' || grid[player_y][player_x] == 'F')
		return ;
	if (grid[player_y][player_x] == 'E')
	{
		map->exit_x = player_x;
		map->exit_y = player_y;
		grid[player_y][player_x] = 'F';
		return ;
	}
	grid[player_y][player_x] = 'F';
	if (player_x > 0)
		ft_fill_path(grid, map, player_x - 1, player_y);
	ft_fill_path(grid, map, player_x + 1, player_y);
	if (player_y > 0)
		ft_fill_path(grid, map, player_x, player_y - 1);
	ft_fill_path(grid, map, player_x, player_y + 1);
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

void	ft_find_player(t_map *map, size_t *player_x, size_t *player_y)
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
				*player_x = x;
				*player_y = y;
				map->player_x = x;
				map->player_y = y;
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
	int		ok;

	ok = 1;
	ft_find_player(map, &player_pos_x, &player_pos_y);
	copy_grid = ft_copy_grid(map->grid);
	if (!copy_grid)
		return (0);
	ft_fill_path(copy_grid, map, player_pos_x, player_pos_y);
	if (!ft_check_collectibles_and_exit(copy_grid))
		ok = 0;
	ft_free_grid(copy_grid);
	return (ok);
}
