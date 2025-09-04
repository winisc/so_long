/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_controll_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:18:36 by wini              #+#    #+#             */
/*   Updated: 2025/09/04 02:21:38 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_moves(int moves)
{
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(moves, 1);
	ft_putendl_fd("", 1);
}

void	ft_render_move(t_game *game, size_t move_x, size_t move_y)
{
	ft_render_image_to_grid(game, game->img_floor, game->map->player_x,
		game->map->player_y);
	game->map->player_x = move_x;
	game->map->player_y = move_y;
	ft_render_image_to_grid(game, game->player->frames[0],
		move_x, move_y);
}

void	ft_collected_claim(t_game *game, size_t move_x, size_t move_y)
{
	game->collectible_now++;
	if (game->collectible_now == game->map->count_collectibles)
	{
		ft_render_image_to_grid(game, game->exit->frames_open[0], game->map->exit_x,
			game->map->exit_y);
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
	ft_print_moves(game->player->moves_now);
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
