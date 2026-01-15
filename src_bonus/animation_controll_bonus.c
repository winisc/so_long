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

void	handle_collectible_animation(t_game *game)
{
	t_collectible	*collectible;
	size_t			i;

	i = 0;
	collectible = game->collectible;
	collectible->frame_counter++;
	if (collectible->frame_counter >= FRAME_RATE_ANIMATIONS)
	{
		while (i < game->map->count_collectibles)
		{
			if (collectible->active[i])
			{
				render_image_to_grid(game,
					collectible->frames[collectible->frame_controll],
					collectible->collectible_x[i],
					collectible->collectible_y[i]);
			}
			i++;
		}
		collectible->frame_controll++;
		if (collectible->frame_controll > 3)
			collectible->frame_controll = 0;
		collectible->frame_counter = 0;
	}
}

void	handle_player_animation(t_game *game)
{
	game->player->frame_counter++;
	if (game->player->frame_counter >= FRAME_RATE_ANIMATIONS)
	{
		render_image_to_grid(game,
			game->player->frames[game->player->frame_controll],
			game->map->player_x, game->map->player_y);
		game->player->frame_controll++;
		if (game->player->frame_controll > 3)
			game->player->frame_controll = 0;
		game->player->frame_counter = 0;
	}
}

void	handle_exit_animation(t_game *game)
{
	game->exit->frame_counter++;
	if (game->exit->frame_counter >= FRAME_RATE_ANIMATIONS)
	{
		if (game->exit->open == 0)
		{
			render_image_to_grid(game,
				game->exit->frame_close[game->exit->frame_controll],
				game->map->exit_x, game->map->exit_y);
		}
		else
		{
			render_image_to_grid(game,
				game->exit->frame_open[game->exit->frame_controll],
				game->map->exit_x, game->map->exit_y);
		}
		game->exit->frame_controll++;
		if (game->exit->frame_controll > 3)
			game->exit->frame_controll = 0;
		game->exit->frame_counter = 0;
	}
}

void	handle_animation(t_game *game)
{
	handle_player_animation(game);
	handle_collectible_animation(game);
	handle_exit_animation(game);
}
