/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_controll_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:40:14 by wini              #+#    #+#             */
/*   Updated: 2025/09/04 02:28:51 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_init_enemy_arrays(t_game *game, size_t total_enemy)
{
	size_t	i;

	game->enemy->enemy_x = malloc(total_enemy * sizeof(int));
	game->enemy->enemy_y = malloc(total_enemy * sizeof(int));
	game->enemy->reset_move = malloc(total_enemy * sizeof(int));
	if (!game->enemy->enemy_x || !game->enemy->enemy_y
		|| !game->enemy->reset_move)
		return (0);
	i = 0;
	while (i < total_enemy)
	{
		game->enemy->reset_move[i] = 0;
		i++;
	}
	return (1);
}

int	ft_save_enemy_positions(t_game *game)
{
	size_t	total_enemy;
	size_t	y;
	size_t	x;

	total_enemy = game->map->count_enemys;
	if (!ft_init_enemy_arrays(game, total_enemy))
		return (0);
	y = 0;
	while (game->map->grid[y])
	{
		x = 0;
		while (game->map->grid[y][x])
		{
			if (game->map->grid[y][x] == 'T')
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

void	ft_attempt_enemy_to_move(t_game *game, size_t enemy_move_y, size_t i)
{
	char	**grid;

	grid = game->map->grid;
	if (grid[enemy_move_y][game->enemy->enemy_x[i]] == '1')
		return ;
	if (grid[enemy_move_y][game->enemy->enemy_x[i]] == 'T')
		return ;
	if (grid[enemy_move_y][game->enemy->enemy_x[i]] == 'E')
		return ;
	grid[game->enemy->enemy_y[i]][game->enemy->enemy_x[i]] = '0';
	ft_render_image_to_grid(game, game->img_floor, game->enemy->enemy_x[i],
		game->enemy->enemy_y[i]);
	game->enemy->enemy_y[i] = enemy_move_y;
	if (grid[game->enemy->enemy_y[i]][game->enemy->enemy_x[i]] == 'P')
		ft_close_game(game);
	grid[game->enemy->enemy_y[i]][game->enemy->enemy_x[i]] = 'T';
	ft_render_image_to_grid(game, game->enemy->img_enemy_1,
		game->enemy->enemy_x[i], game->enemy->enemy_y[i]);
}

void	ft_move_enemy_controll(t_game *game)
{
	size_t	enemy_move_y;
	size_t	i;

	i = 0;
	enemy_move_y = 0;
	while (i < game->map->count_enemys)
	{
		if (game->enemy->reset_move[i] == 0 || game->enemy->reset_move[i] == 3)
		{
			enemy_move_y = game->enemy->enemy_y[i] - 1;
			ft_attempt_enemy_to_move(game, enemy_move_y, i);
		}
		if (game->enemy->reset_move[i] == 1 || game->enemy->reset_move[i] == 2)
		{
			enemy_move_y = game->enemy->enemy_y[i] + 1;
			ft_attempt_enemy_to_move(game, enemy_move_y, i);
		}
		game->enemy->reset_move[i]++;
		if (game->enemy->reset_move[i] > 3)
			game->enemy->reset_move[i] = 0;
		i++;
	}
}
