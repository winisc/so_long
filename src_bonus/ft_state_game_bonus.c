/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state_game_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:40:14 by wini              #+#    #+#             */
/*   Updated: 2025/09/01 01:56:08 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_close_game(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player_anim_1)
		mlx_destroy_image(game->mlx, game->img_player_anim_1);
	if (game->img_player_anim_2)
		mlx_destroy_image(game->mlx, game->img_player_anim_2);
	if (game->img_player_anim_3)
		mlx_destroy_image(game->mlx, game->img_player_anim_3);
	if (game->img_player_anim_4)
		mlx_destroy_image(game->mlx, game->img_player_anim_4);
	if (game->img_player_anim_5)
		mlx_destroy_image(game->mlx, game->img_player_anim_5);
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

int	ft_handle_animation(t_game *game)
{
	game->frame_counter++;

	if (game->frame_counter >= 1000)
	{
		if (game->frame_controll == 1)
		{
			ft_render_image_to_grid(game, game->img_player_anim_1,
				game->map->px, game->map->py);
			game->frame_controll = 2;
		}
		else if (game->frame_controll == 2)
		{
			ft_render_image_to_grid(game, game->img_player_anim_2,
				game->map->px, game->map->py);
			game->frame_controll = 3;
		}
		else if (game->frame_controll == 3)
		{
			ft_render_image_to_grid(game, game->img_player_anim_3,
				game->map->px, game->map->py);
			game->frame_controll = 4;
		}
		else if (game->frame_controll == 4)
		{
			ft_render_image_to_grid(game, game->img_player_anim_4,
				game->map->px, game->map->py);
			game->frame_controll = 5;
		}
		else
		{
			ft_render_image_to_grid(game, game->img_player_anim_5,
				game->map->px, game->map->py);
			game->frame_controll = 1;
		}
		game->frame_counter = 0;
	}
	return (0);
}

