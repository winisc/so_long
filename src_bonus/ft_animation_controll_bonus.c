/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_controll.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:40:14 by wini              #+#    #+#             */
/*   Updated: 2025/09/02 23:21:27 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_handle_player_animation(t_game *game)
{
	game->player->frame_counter++;
	if (game->player->frame_counter >= FRAME_RATE_ANIMATIONS)
	{
		ft_render_image_to_grid(game,
			game->player->frames[game->player->frame_controll],
			game->map->player_x, game->map->player_y);
		game->player->frame_controll++;
		if (game->player->frame_controll > 4)
			game->player->frame_controll = 0;
		game->player->frame_counter = 0;
	}
}

void	ft_handle_exit_animation(t_game *game)
{
	if (game->exit->open == 0)
		return ;
	game->exit->frame_counter++;
	if (game->exit->frame_counter >= 6000)
	{
		ft_render_image_to_grid(game,
			game->exit->frames_open[game->exit->frame_controll],
			game->map->exit_x, game->map->exit_y);
		game->exit->frame_controll++;
		if (game->exit->frame_controll > 2)
			game->exit->frame_controll = 0;
		game->exit->frame_counter = 0;
	}
}

void	ft_handle_animation(t_game *game)
{
	ft_handle_player_animation(game);
	ft_handle_exit_animation(game);
}
