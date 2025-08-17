/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_controll.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:18:36 by wini              #+#    #+#             */
/*   Updated: 2025/08/17 20:18:20 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_move(size_t move_x, size_t move_y, t_game *game)
{
	char	**grid;

	grid = game->map->grid;
	if (grid[move_y][move_x] == '1')
		return (0);
	if (grid[move_y][move_x] == 'C')
	{
		game->collectible_now++;
		grid[move_y][move_x] = '0';
	}
	else if (grid[move_y][move_x] == 'E')
	{
		if (game->collectible_now == game->map->count_collectibles)
			ft_close_game(game);
		else
			return (0);
	}
	ft_render_image_to_grid(game, game->img_floor, game->map->px,
		game->map->py);
	game->map->px = move_x;
	game->map->py = move_y;
	ft_render_image_to_grid(game, game->img_player, move_x, move_y);
	game->moves++;
	printf("Moves: %zu\n", game->moves);
	return (1);
}

void	ft_attempt_to_move(size_t move_x, size_t move_y, t_game *game)
{
	if (!ft_check_move(move_x, move_y, game))
		return ;
}

void	ft_player_move(t_game *game, char *direction)
{
	size_t	px;
	size_t	py;

	px = game->map->px;
	py = game->map->py;
	if (ft_strncmp(direction, "up", 2) == 0)
		ft_attempt_to_move(px, py - 1, game);
	else if (ft_strncmp(direction, "down", 4) == 0)
		ft_attempt_to_move(px, py + 1, game);
	else if (ft_strncmp(direction, "left", 4) == 0)
		ft_attempt_to_move(px - 1, py, game);
	else if (ft_strncmp(direction, "right", 5) == 0)
		ft_attempt_to_move(px + 1, py, game);
}
