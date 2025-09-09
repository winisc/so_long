/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 02:25:54 by wini              #+#    #+#             */
/*   Updated: 2025/09/09 01:39:13 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_destroy_player(t_game *game)
{
	int	i;

	if (!game->player)
		return ;
	i = 0;
	while (i < 4)
	{
		if (game->player->frames[i])
			mlx_destroy_image(game->mlx, game->player->frames[i]);
		i++;
	}
	free(game->player);
}

static void	ft_destroy_collectible(t_game *game)
{
	int	i;

	if (!game->collectible)
		return ;
	i = 0;
	while (i < 4)
	{
		if (game->collectible->frames[i])
			mlx_destroy_image(game->mlx, game->collectible->frames[i]);
		i++;
	}
	if (game->collectible->active)
		free(game->collectible->active);
	if (game->collectible->collectible_x)
		free(game->collectible->collectible_x);
	if (game->collectible->collectible_y)
		free(game->collectible->collectible_y);
	free(game->collectible);
}

static void	ft_destroy_enemy(t_game *game)
{
	if (!game->enemy)
		return ;
	if (game->enemy->reset_move)
		free(game->enemy->reset_move);
	if (game->enemy->enemy_x)
		free(game->enemy->enemy_x);
	if (game->enemy->enemy_y)
		free(game->enemy->enemy_y);
	if (game->enemy->frame_up)
		mlx_destroy_image(game->mlx, game->enemy->frame_up);
	if (game->enemy->frame_down)
		mlx_destroy_image(game->mlx, game->enemy->frame_down);
	free(game->enemy);
}

static void	ft_destroy_exit(t_game *game)
{
	int	i;

	if (!game->exit)
		return ;
	i = 0;
	while (i < 4)
	{
		if (game->exit->frame_open[i])
			mlx_destroy_image(game->mlx, game->exit->frame_open[i]);
		if (game->exit->frame_close[i])
			mlx_destroy_image(game->mlx, game->exit->frame_close[i]);
		i++;
	}
	free(game->exit);
}

int	ft_close_game(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	ft_destroy_player(game);
	ft_destroy_collectible(game);
	ft_destroy_enemy(game);
	ft_destroy_exit(game);
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
