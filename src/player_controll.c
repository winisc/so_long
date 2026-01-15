/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_controll.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:18:36 by wini              #+#    #+#             */
/*   Updated: 2025/09/07 02:40:42 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(int moves)
{
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(moves, 1);
	ft_putendl_fd("", 1);
}

void	render_move(t_game *game, size_t move_x, size_t move_y)
{
	game->map->grid[game->map->player_y][game->map->player_x] = '0';
	render_image_to_grid(game, game->img_floor, game->map->player_x,
		game->map->player_y);
	game->map->player_x = move_x;
	game->map->player_y = move_y;
	game->map->grid[move_y][move_x] = 'P';
	render_image_to_grid(game, game->img_player, move_x, move_y);
}

void	open_exit(t_game *game)
{
	render_image_to_grid(game, game->img_exit_open, game->map->exit_x,
		game->map->exit_y);
}

void	attempt_to_move(size_t move_x, size_t move_y, t_game *game)
{
	char	**grid;

	grid = game->map->grid;
	if (grid[move_y][move_x] == '1')
		return ;
	else if (grid[move_y][move_x] == 'C')
	{
		game->collectible_now++;
		if (game->collectible_now == game->map->count_collectibles)
			open_exit(game);
		grid[move_y][move_x] = '0';
	}
	else if (grid[move_y][move_x] == 'E')
	{
		if (game->collectible_now == game->map->count_collectibles)
			close_game(game);
		else
			return ;
	}
	render_move(game, move_x, move_y);
	game->moves_now++;
	print_moves(game->moves_now);
	return ;
}

void	player_move(t_game *game, char *direction)
{
	size_t	player_x;
	size_t	player_y;

	player_x = game->map->player_x;
	player_y = game->map->player_y;
	if (ft_strncmp(direction, "up", 2) == 0)
		attempt_to_move(player_x, player_y - 1, game);
	else if (ft_strncmp(direction, "down", 4) == 0)
		attempt_to_move(player_x, player_y + 1, game);
	else if (ft_strncmp(direction, "left", 4) == 0)
		attempt_to_move(player_x - 1, player_y, game);
	else if (ft_strncmp(direction, "right", 5) == 0)
		attempt_to_move(player_x + 1, player_y, game);
}
