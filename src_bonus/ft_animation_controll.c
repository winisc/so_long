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

int	ft_handle_animation(t_game *game)
{
	game->player->frame_counter++;

	if (game->player->frame_counter >= FRAME_RATE)
	{
		if (game->player->frame_controll == 1)
		{
			ft_render_image_to_grid(game, game->player->img_player_anim_1,
				game->map->player_x, game->map->player_y);
			game->player->frame_controll = 2;
		}
		else if (game->player->frame_controll == 2)
		{
			ft_render_image_to_grid(game, game->player->img_player_anim_2,
				game->map->player_x, game->map->player_y);
			game->player->frame_controll = 3;
		}
		else if (game->player->frame_controll == 3)
		{
			ft_render_image_to_grid(game, game->player->img_player_anim_3,
				game->map->player_x, game->map->player_y);
			game->player->frame_controll = 4;
		}
		else if (game->player->frame_controll == 4)
		{
			ft_render_image_to_grid(game, game->player->img_player_anim_4,
				game->map->player_x, game->map->player_y);
			game->player->frame_controll = 5;
		}
		else
		{
			ft_render_image_to_grid(game, game->player->img_player_anim_5,
				game->map->player_x, game->map->player_y);
			game->player->frame_controll = 1;
		}
		game->player->frame_counter = 0;
	}

	game->exit->frame_counter++;

	if (game->exit->frame_counter >= FRAME_RATE)
	{
		if (game->exit->frame_controll == 1)
		{
			ft_render_image_to_grid(game, game->exit->img_exit_close_anim_1,
				game->map->exit_x, game->map->exit_y);
			game->exit->frame_controll = 2;
		}
		else if (game->exit->frame_controll == 2)
		{
			ft_render_image_to_grid(game, game->exit->img_exit_close_anim_2,
				game->map->exit_x, game->map->exit_y);
			game->exit->frame_controll = 3;
		}
		else if (game->exit->frame_controll == 3)
		{
			ft_render_image_to_grid(game, game->exit->img_exit_close_anim_3,
				game->map->exit_x, game->map->exit_y);
			game->exit->frame_controll = 4;
		}
		else if (game->exit->frame_controll == 4)
		{
			ft_render_image_to_grid(game, game->exit->img_exit_close_anim_4,
				game->map->exit_x, game->map->exit_y);
			game->exit->frame_controll = 5;
		}
		else
		{
			ft_render_image_to_grid(game, game->exit->img_exit_close_anim_5,
				game->map->exit_x, game->map->exit_y);
			game->exit->frame_controll = 1;
		}
		game->exit->frame_counter = 0;
	}
	return (0);
}
