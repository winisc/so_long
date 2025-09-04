/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_entitys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 02:04:11 by wini              #+#    #+#             */
/*   Updated: 2025/09/04 02:16:59 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_player(t_game *game)
{
	int	i;

	if (!game->player)
		return ;
	i = 0;
	while (i < 5)
	{
		game->player->frames[i] = NULL;
		i++;
	}
	game->player->frame_controll = 0;
	game->player->frame_counter = 0;
	game->player->moves_now = 0;
}

void	ft_init_collectible(t_game *game)
{
	if (!game->collectible)
		return ;
	game->collectible->img_collectible_anim_1 = NULL;
	game->collectible->frame_controll = 0;
	game->collectible->frame_counter = 0;
}

void	ft_init_enemy(t_game *game)
{
	if (!game->enemy)
		return ;
	game->enemy->img_enemy_anim_1 = NULL;
	game->enemy->frame_controll = 0;
	game->enemy->frame_counter = 0;
}

void	ft_init_exit(t_game *game)
{
	int	i;

	if (!game->exit)
		return ;
	i = 0;
	while (i < 5)
	{
		game->exit->frames_open[i] = NULL;
		i++;
	}
	game->exit->img_exit_close = NULL;
	game->exit->frame_controll = 0;
	game->exit->frame_counter = 0;
	game->exit->open = 0;
}

void	ft_init_entitys(t_game *game)
{
	game->img_wall = NULL;
	game->img_floor = NULL;
	ft_init_player(game);
	ft_init_collectible(game);
	ft_init_enemy(game);
	ft_init_exit(game);
}
