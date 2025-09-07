/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_controll_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:40:14 by wini              #+#    #+#             */
/*   Updated: 2025/09/04 02:28:51 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_save_enemy_positions(t_game *game)
{
	char	**grid;
	size_t	total_enemy;
	size_t	y;
	size_t	x;

	total_enemy = game->map->count_enemys;
	grid = game->map->grid;
	game->enemy->enemy_x = malloc(total_enemy * sizeof(int));
	game->enemy->enemy_y = malloc(total_enemy * sizeof(int));
	game->enemy->reset_move = malloc(total_enemy * sizeof(int));
	if (!game->enemy->enemy_x || !game->enemy->enemy_y || !game->enemy->reset_move)
		return (0);
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'T')
			{
				total_enemy--;
				game->enemy->enemy_x[total_enemy] = x;
				game->enemy->enemy_y[total_enemy] = y;
			}
			x++;
		}
		y++;
	}
	return (1);
}

void ft_move_enemy_controll(t_game *game)
{
	t_enemy	*enemys;
	char	**grid;
	size_t	enemy_move_y;
	size_t	i;

	i = 0;
	enemy_move_y = 0;
	enemys = game->enemy;
	grid = game->map->grid;
	while (i < game->map->count_enemys)
	{
		if (enemys->reset_move[i] == 0)
		{
			enemy_move_y = enemys->enemy_y[i] - 1;
			if (grid[enemy_move_y][enemys->enemy_x[i]] != '1' && grid[enemy_move_y][enemys->enemy_x[i]] != 'T' && grid[enemy_move_y][enemys->enemy_x[i]] != 'E')
			{
				grid[enemys->enemy_y[i]][enemys->enemy_x[i]] = '0';
				ft_render_image_to_grid(game, game->img_floor, enemys->enemy_x[i],
					enemys->enemy_y[i]);
				enemys->enemy_y[i] = enemy_move_y;
				if (grid[enemys->enemy_y[i]][enemys->enemy_x[i]] == 'P')
					ft_close_game(game);
				grid[enemys->enemy_y[i]][enemys->enemy_x[i]] = 'T';
				ft_render_image_to_grid(game, game->enemy->img_enemy_anim_1,
					enemys->enemy_x[i], enemys->enemy_y[i]);
			}
		}
		if (enemys->reset_move[i] == 1)
		{
			enemy_move_y = enemys->enemy_y[i] + 1;
			if (grid[enemy_move_y][enemys->enemy_x[i]] != '1' && grid[enemy_move_y][enemys->enemy_x[i]] != 'T' && grid[enemy_move_y][enemys->enemy_x[i]] != 'E')
			{
				grid[enemys->enemy_y[i]][enemys->enemy_x[i]] = '0';
				ft_render_image_to_grid(game, game->img_floor, enemys->enemy_x[i],
					enemys->enemy_y[i]);
				enemys->enemy_y[i] = enemy_move_y;
				if (grid[enemys->enemy_y[i]][enemys->enemy_x[i]] == 'P')
					ft_close_game(game);
				grid[enemys->enemy_y[i]][enemys->enemy_x[i]] = 'T';
				ft_render_image_to_grid(game, game->enemy->img_enemy_anim_1,
					enemys->enemy_x[i], enemys->enemy_y[i]);
			}
		}
		if (enemys->reset_move[i] == 2)
		{
			enemy_move_y = enemys->enemy_y[i] + 1;
			if (grid[enemy_move_y][enemys->enemy_x[i]] != '1' && grid[enemy_move_y][enemys->enemy_x[i]] != 'T' && grid[enemy_move_y][enemys->enemy_x[i]] != 'E')
			{
				grid[enemys->enemy_y[i]][enemys->enemy_x[i]] = '0';
				ft_render_image_to_grid(game, game->img_floor, enemys->enemy_x[i],
					enemys->enemy_y[i]);
				enemys->enemy_y[i] = enemy_move_y;
				if (grid[enemys->enemy_y[i]][enemys->enemy_x[i]] == 'P')
					ft_close_game(game);
				grid[enemys->enemy_y[i]][enemys->enemy_x[i]] = 'T';
				ft_render_image_to_grid(game, game->enemy->img_enemy_anim_1,
					enemys->enemy_x[i], enemys->enemy_y[i]);
			}
		}
		if (enemys->reset_move[i] == 3)
		{
			enemy_move_y = enemys->enemy_y[i] - 1;
			if (grid[enemy_move_y][enemys->enemy_x[i]] != '1' && grid[enemy_move_y][enemys->enemy_x[i]] != 'T' && grid[enemy_move_y][enemys->enemy_x[i]] != 'E')
			{
				grid[enemys->enemy_y[i]][enemys->enemy_x[i]] = '0';
				ft_render_image_to_grid(game, game->img_floor, enemys->enemy_x[i],
					enemys->enemy_y[i]);
				enemys->enemy_y[i] = enemy_move_y;
				if (grid[enemys->enemy_y[i]][enemys->enemy_x[i]] == 'P')
					ft_close_game(game);
				grid[enemys->enemy_y[i]][enemys->enemy_x[i]] = 'T';
				ft_render_image_to_grid(game, game->enemy->img_enemy_anim_1,
					enemys->enemy_x[i], enemys->enemy_y[i]);
			}
		}
		enemys->reset_move[i]++;
		if (enemys->reset_move[i] > 3)
			enemys->reset_move[i] = 0;
		i++;
	}
}
