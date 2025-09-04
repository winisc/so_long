/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 01:25:36 by wini              #+#    #+#             */
/*   Updated: 2025/09/04 02:47:41 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_load_assets_player(t_game *game, int w, int h)
{
	char	*paths[5];
	int		i;

	paths[0] = "assets/bonus/player/player_anim_1.xpm";
	paths[1] = "assets/bonus/player/player_anim_2.xpm";
	paths[2] = "assets/bonus/player/player_anim_3.xpm";
	paths[3] = "assets/bonus/player/player_anim_4.xpm";
	paths[4] = "assets/bonus/player/player_anim_5.xpm";
	i = 0;
	while (i < 5)
	{
		game->player->frames[i] = mlx_xpm_file_to_image(game->mlx,
				paths[i], &w, &h);
		if (!game->player->frames[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_load_assets_exit_open(t_game *game, int w, int h)
{
	char	*paths[5];
	int		i;

	paths[0] = "assets/bonus/exit_open/exit_open_anim_1.xpm";
	paths[1] = "assets/bonus/exit_open/exit_open_anim_2.xpm";
	paths[2] = "assets/bonus/exit_open/exit_open_anim_3.xpm";
	paths[3] = "assets/bonus/exit_open/exit_open_anim_4.xpm";
	paths[4] = "assets/bonus/exit_open/exit_open_anim_5.xpm";
	i = 0;
	while (i < 5)
	{
		game->exit->frames_open[i] = mlx_xpm_file_to_image(game->mlx,
				paths[i], &w, &h);
		if (!game->exit->frames_open[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_load_assets(t_game *game, int w, int h)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"assets/bonus/wall.xpm", &w, &h);
	if (!game->img_wall)
		return (0);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"assets/bonus/floor.xpm", &w, &h);
	if (!game->img_floor)
		return (0);
	game->exit->img_exit_close = mlx_xpm_file_to_image(game->mlx,
			"assets/bonus/exit_close/exit_close.xpm", &w, &h);
	if (!game->exit->img_exit_close)
		return (0);
	game->enemy->img_enemy_anim_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/bonus/enemy/enemy.xpm", &w, &h);
	if (!game->enemy->img_enemy_anim_1)
		return (0);
	game->collectible->img_collectible_anim_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/bonus/collectible.xpm", &w, &h);
	if (!game->collectible->img_collectible_anim_1)
		return (0);
	if (!ft_load_assets_player(game, w, h))
		return (0);
	if (!ft_load_assets_exit_open(game, w, h))
		return (0);
	return (1);
}
