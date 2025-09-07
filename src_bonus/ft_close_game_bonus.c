/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 02:25:54 by wini              #+#    #+#             */
/*   Updated: 2025/09/07 02:51:04 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_destroy_player(t_game *game)
{
	int	i;

	if (!game->player)
		return ;
	i = 0;
	while (i < 5)
	{
		if (game->player->frames[i])
			mlx_destroy_image(game->mlx, game->player->frames[i]);
		i++;
	}
	free(game->player);
}

static void	ft_destroy_collectible(t_game *game)
{
	if (!game->collectible)
		return ;
	if (game->collectible->img_collectible_1)
		mlx_destroy_image(game->mlx, game->collectible->img_collectible_1);
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
	if (game->enemy->img_enemy_1)
		mlx_destroy_image(game->mlx, game->enemy->img_enemy_1);
	free(game->enemy);
}

static void	ft_destroy_exit(t_game *game)
{
	int	i;

	if (!game->exit)
		return ;
	if (game->exit->img_exit_close)
		mlx_destroy_image(game->mlx, game->exit->img_exit_close);
	i = 0;
	while (i < 5)
	{
		if (game->exit->frames_open[i])
			mlx_destroy_image(game->mlx, game->exit->frames_open[i]);
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
