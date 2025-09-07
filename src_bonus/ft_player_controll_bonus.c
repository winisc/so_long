/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_controll_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:18:36 by wini              #+#    #+#             */
/*   Updated: 2025/09/07 03:43:04 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_infos(t_game *game)
{
	char	*moves_now;
	char	*collectibles_now;

	moves_now = ft_itoa(game->player->moves_now);
	collectibles_now = ft_itoa(game->collectible_now);
	ft_render_image_to_grid(game, game->img_floor, 1, -1);
	mlx_string_put(game->mlx, game->win, 70, 24, 0x000000, moves_now);
	mlx_string_put(game->mlx, game->win, 70, 44, 0x000000, collectibles_now);
	free(moves_now);
	free(collectibles_now);
}

void	ft_render_move(t_game *game, size_t move_x, size_t move_y)
{
	game->map->grid[game->map->player_y][game->map->player_x] = '0';
	ft_render_image_to_grid(game, game->img_floor, game->map->player_x,
		game->map->player_y);
	game->map->player_x = move_x;
	game->map->player_y = move_y;
	game->map->grid[move_y][move_x] = 'P';
	ft_render_image_to_grid(game, game->player->frames[0],
		move_x, move_y);
}

void	ft_collected_claim(t_game *game, size_t move_x, size_t move_y)
{
	game->collectible_now++;
	if (game->collectible_now == game->map->count_collectibles)
	{
		ft_render_image_to_grid(game, game->exit->frames_open[0],
			game->map->exit_x, game->map->exit_y);
		game->exit->open = 1;
	}
	game->map->grid[move_y][move_x] = '0';
}

void	ft_attempt_to_move(size_t move_x, size_t move_y, t_game *game)
{
	char	**grid;

	grid = game->map->grid;
	if (grid[move_y][move_x] == '1')
		return ;
	else if (grid[move_y][move_x] == 'C')
		ft_collected_claim(game, move_x, move_y);
	else if (grid[move_y][move_x] == 'T')
		ft_close_game(game);
	else if (grid[move_y][move_x] == 'E')
	{
		if (game->collectible_now == game->map->count_collectibles)
			ft_close_game(game);
		else
			return ;
	}
	ft_render_move(game, move_x, move_y);
	game->player->moves_now++;
	ft_print_infos(game);
	return ;
}

void	ft_player_move(t_game *game, char *direction)
{
	size_t	player_x;
	size_t	player_y;

	player_x = game->map->player_x;
	player_y = game->map->player_y;
	if (ft_strncmp(direction, "up", 2) == 0)
		ft_attempt_to_move(player_x, player_y - 1, game);
	else if (ft_strncmp(direction, "down", 4) == 0)
		ft_attempt_to_move(player_x, player_y + 1, game);
	else if (ft_strncmp(direction, "left", 4) == 0)
		ft_attempt_to_move(player_x - 1, player_y, game);
	else if (ft_strncmp(direction, "right", 5) == 0)
		ft_attempt_to_move(player_x + 1, player_y, game);
}
