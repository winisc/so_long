/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:28:59 by wini              #+#    #+#             */
/*   Updated: 2025/09/13 20:47:07 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_calculate_center_map(t_game *game, size_t *pos)
{
	size_t	height;
	size_t	width;

	width = game->map->width;
	height = game->map->height;
	pos[0] = width / 2;
	pos[1] = height / 2;
}

void	render_game_over(t_game *game)
{
	size_t	x;
	size_t	y;
	size_t	center_map[2];
	char	**grid;

	ft_calculate_center_map(game, center_map);
	game->state = 0;
	grid = game->map->grid;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			render_image_to_grid(game, game->img_floor, x, y);
			if (x == center_map[0] - 1 && y == center_map[1])
				render_image_to_grid(game, game->enemy->frame_down, x, y);
			if (x == center_map[0] && y == center_map[1])
				render_image_to_grid(game, game->enemy->frame_down, x, y);
			if (x == center_map[0] + 1 && y == center_map[1])
				render_image_to_grid(game, game->enemy->frame_down, x, y);
			x++;
		}
		y++;
	}
}

void	render_victory(t_game *game)
{
	size_t	x;
	size_t	y;
	size_t	center_map[2];
	char	**grid;

	ft_calculate_center_map(game, center_map);
	game->state = 0;
	grid = game->map->grid;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			render_image_to_grid(game, game->img_floor, x, y);
			if (x == center_map[0] && y == center_map[1])
				render_image_to_grid(game, game->player->frames[0], x, y);
			if (x == center_map[0] && y == center_map[1] - 1)
				mlx_string_put(game->mlx, game->win, (x * TILE_SIZE) + 4,
					((y + 1) * TILE_SIZE) + (TILE_SIZE / 2 + 10),
					0xffffff, "VICTORY");
			x++;
		}
		y++;
	}
}
