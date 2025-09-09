/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collectible_controll_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 01:39:27 by wini              #+#    #+#             */
/*   Updated: 2025/09/09 01:56:11 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_disable_collectible_now(t_game *game, size_t x, size_t y)
{
	t_collectible	*collectible;
	size_t			total_collectibles;
	size_t			i;

	collectible = game->collectible;
	total_collectibles = game->map->count_collectibles;
	i = 0;
	while (i < total_collectibles)
	{
		if (x == collectible->collectible_x[i]
			&& y == collectible->collectible_y[i])
			collectible->active[i] = 0;
		i++;
	}
}

int	ft_init_collectible_arrays(t_game *game, size_t total_collectible)
{
	game->collectible->collectible_x = malloc
		(total_collectible * sizeof(size_t));
	game->collectible->collectible_y = malloc
		(total_collectible * sizeof(size_t));
	game->collectible->active = malloc(total_collectible * sizeof(int));
	if (!game->collectible->collectible_x || !game->collectible->collectible_y
		|| !game->collectible->active)
		return (0);
	return (1);
}

int	ft_save_collectible_positions(t_game *game)
{
	size_t	total_collectibles;
	size_t	y;
	size_t	x;

	total_collectibles = game->map->count_collectibles;
	if (!ft_init_collectible_arrays(game, total_collectibles))
		return (0);
	y = 0;
	while (game->map->grid[y])
	{
		x = 0;
		while (game->map->grid[y][x])
		{
			if (game->map->grid[y][x] == 'C')
			{
				total_collectibles--;
				game->collectible->active[total_collectibles] = 1;
				game->collectible->collectible_x[total_collectibles] = x;
				game->collectible->collectible_y[total_collectibles] = y;
			}
			x++;
		}
		y++;
	}
	return (1);
}
