/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state_game_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsilveir <wsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:40:14 by wini              #+#    #+#             */
/*   Updated: 2025/09/03 21:57:34 by wsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_close_game(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->player->img_player_anim_1)
		mlx_destroy_image(game->mlx, game->player->img_player_anim_1);
	if (game->player->img_player_anim_2)
		mlx_destroy_image(game->mlx, game->player->img_player_anim_2);
	if (game->player->img_player_anim_3)
		mlx_destroy_image(game->mlx, game->player->img_player_anim_3);
	if (game->player->img_player_anim_4)
		mlx_destroy_image(game->mlx, game->player->img_player_anim_4);
	if (game->player->img_player_anim_5)
		mlx_destroy_image(game->mlx, game->player->img_player_anim_5);
	if (game->collectible->img_collectible_anim_1)
		mlx_destroy_image(game->mlx, game->collectible->img_collectible_anim_1);
	if (game->exit->img_exit_open)
		mlx_destroy_image(game->mlx, game->exit->img_exit_open);
	if (game->exit->img_exit_close_anim_1)
		mlx_destroy_image(game->mlx, game->exit->img_exit_close_anim_1);
	if (game->exit->img_exit_close_anim_2)
		mlx_destroy_image(game->mlx, game->exit->img_exit_close_anim_2);
	if (game->exit->img_exit_close_anim_3)
		mlx_destroy_image(game->mlx, game->exit->img_exit_close_anim_3);
	if (game->exit->img_exit_close_anim_4)
		mlx_destroy_image(game->mlx, game->exit->img_exit_close_anim_4);
	if (game->exit->img_exit_close_anim_5)
		mlx_destroy_image(game->mlx, game->exit->img_exit_close_anim_5);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		ft_free_load_map(game->map);
	if (game->player)
		free(game->player);
	if (game->enemy)
		free(game->enemy);
	if (game->collectible)
		free(game->collectible);
	if (game->exit)
		free(game->exit);
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
