/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsilveir <wsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:40:14 by wini              #+#    #+#             */
/*   Updated: 2025/08/24 17:47:08 by wsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_game(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_exit_close)
		mlx_destroy_image(game->mlx, game->img_exit_close);
	if (game->img_exit_open)
		mlx_destroy_image(game->mlx, game->img_exit_open);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		ft_free_load_map(game->map);
	exit(0);
	return (0);
}

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_close_game(game);
	if (keycode == 97)
		ft_player_move(game, "left");
	if (keycode == 100)
		ft_player_move(game, "right");
	if (keycode == 115)
		ft_player_move(game, "down");
	if (keycode == 119)
		ft_player_move(game, "up");
	return (0);
}
