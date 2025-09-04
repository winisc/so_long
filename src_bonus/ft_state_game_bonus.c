/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state_game_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:40:14 by wini              #+#    #+#             */
/*   Updated: 2025/09/04 02:28:51 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	ft_handle_player_animation(game);
	ft_handle_exit_animation(game);
	return (0);
}
