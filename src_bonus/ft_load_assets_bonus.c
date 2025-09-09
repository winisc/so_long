/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_assets_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 01:25:36 by wini              #+#    #+#             */
/*   Updated: 2025/09/09 01:10:18 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_load_assets_player(t_game *game, int w, int h)
{
	char	*paths[4];
	int		i;

	paths[0] = "assets/bonus/player/player_anim_1.xpm";
	paths[1] = "assets/bonus/player/player_anim_2.xpm";
	paths[2] = "assets/bonus/player/player_anim_3.xpm";
	paths[3] = "assets/bonus/player/player_anim_4.xpm";
	i = 0;
	while (i < 4)
	{
		game->player->frames[i] = mlx_xpm_file_to_image(game->mlx,
				paths[i], &w, &h);
		if (!game->player->frames[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_load_assets_collectible(t_game *game, int w, int h)
{
	char	*paths[4];
	int		i;

	paths[0] = "assets/bonus/collectible/collectible_anim_1.xpm";
	paths[1] = "assets/bonus/collectible/collectible_anim_2.xpm";
	paths[2] = "assets/bonus/collectible/collectible_anim_3.xpm";
	paths[3] = "assets/bonus/collectible/collectible_anim_4.xpm";
	i = 0;
	while (i < 4)
	{
		game->collectible->frames[i] = mlx_xpm_file_to_image(game->mlx,
				paths[i], &w, &h);
		if (!game->collectible->frames[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_load_assets_exit(t_game *game, int w, int h)
{
	char	*paths_open[4];
	char	*paths_close[4];
	int		i;

	paths_open[0] = "assets/bonus/exit_open/exit_open_anim_1.xpm";
	paths_open[1] = "assets/bonus/exit_open/exit_open_anim_2.xpm";
	paths_open[2] = "assets/bonus/exit_open/exit_open_anim_3.xpm";
	paths_open[3] = "assets/bonus/exit_open/exit_open_anim_4.xpm";
	paths_close[0] = "assets/bonus/exit_close/exit_close_anim_1.xpm";
	paths_close[1] = "assets/bonus/exit_close/exit_close_anim_2.xpm";
	paths_close[2] = "assets/bonus/exit_close/exit_close_anim_3.xpm";
	paths_close[3] = "assets/bonus/exit_close/exit_close_anim_4.xpm";
	i = 0;
	while (i < 4)
	{
		game->exit->frame_open[i] = mlx_xpm_file_to_image(game->mlx,
				paths_open[i], &w, &h);
		game->exit->frame_close[i] = mlx_xpm_file_to_image(game->mlx,
				paths_close[i], &w, &h);
		if (!game->exit->frame_open[i] || !game->exit->frame_close[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_load_assets_enemy(t_game *game, int w, int h)
{
	char	*path_enemy_up;
	char	*path_enemy_down;

	path_enemy_up = "assets/bonus/enemy/enemy_up.xpm";
	path_enemy_down = "assets/bonus/enemy/enemy_down.xpm";
	game->enemy->frame_up = mlx_xpm_file_to_image(game->mlx,
			path_enemy_up, &w, &h);
	game->enemy->frame_down = mlx_xpm_file_to_image(game->mlx,
			path_enemy_down, &w, &h);
	if (!game->enemy->frame_up || !game->enemy->frame_down)
		return (0);
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
	if (!ft_load_assets_player(game, w, h))
		return (0);
	if (!ft_load_assets_collectible(game, w, h))
		return (0);
	if (!ft_load_assets_exit(game, w, h))
		return (0);
	if (!ft_load_assets_enemy(game, w, h))
		return (0);
	return (1);
}
