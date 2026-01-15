/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state_game_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:40:14 by wini              #+#    #+#             */
/*   Updated: 2025/09/13 20:46:25 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_hook(int keycode, t_game *game)
{
	if (game->state)
	{
		if (keycode == 65307)
			close_game(game);
		if (keycode == 97)
			player_move(game, "left");
		if (keycode == 100)
			player_move(game, "right");
		if (keycode == 115)
			player_move(game, "down");
		if (keycode == 119)
			player_move(game, "up");
	}
	return (1);
}

int	controll_state_game(t_game *game)
{
	if (!game->state)
	{
		game->frame_counter++;
		if (game->frame_counter >= FRAME_RATE_EVENTS * 3)
			close_game(game);
		return (0);
	}
	handle_animation(game);
	game->frame_counter++;
	if (game->frame_counter >= FRAME_RATE_EVENTS)
	{
		move_enemy_controll(game);
		game->frame_counter = 0;
	}
	return (1);
}
